/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 10:09:19 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/02 15:33:39 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/init.h>

extern char const	*g_optarg;

void		sh_testing(const char *arg, char *const *av, char **environ)
{
	if (ft_strequ(arg, "env"))
		sh_testing_env(av, environ);
	if (ft_strequ(arg, "lexer"))
		sh_testing_lexer(av);
	if (ft_strequ(arg, "parser"))
		sh_testing_parser(av);
	if (ft_strequ(arg, "ast"))
		sh_testing_ast(av, environ);
	if (ft_strequ(arg, "expand"))
		sh_testing_expand(av, environ);
	else
	{
		ft_dprintf(STDERR_FILENO, "Unknown testing arg.\n");
		sh_usage_help_exit();
	}
}

static void	sh_options(t_sh_opt *opts, int ac, char *const *av, char **environ)
{
	int opt;

	opts->tcaps = true;
	while ((opt = ft_getopt(ac, av, "chvd:t:l")) >= 0)
	{
		if (opt == 'v')
			opts->verbose = 1;
		else if (opt == 'd')
			if (ft_atoi(g_optarg) >= 0 && ft_atoi(g_optarg) <= 7)
				logger_init(ft_atoi(g_optarg), PROGNAME, "sh.log");
			else
			{
				ft_printf("%s: Invalid debug level.\n", PROGNAME);
				sh_usage_help_exit();
			}
		else if (opt == 'h' || opt == '?')
			sh_usage_help_exit();
		else if (opt == 't')
			sh_testing(g_optarg, av, environ);
		else if (opt == 'l')
			opts->tcaps = false;
		else if (opt == 'c')
			sh_testing_exec(av, environ);
	}
}

t_sh_data	*sh_init(t_sh_data *data, int ac, char *const *av, char **environ)
{
	ft_bzero(data, sizeof(*data));
	sh_options(&data->opts, ac, av, environ);
	sh_init_environ(environ);
	sh_builtins_init();
	sh_history_init(NULL);
	//init_signals(signals_handler);
	sh_store_tattr(data);
	if ((data->cwd = getcwd(data->cwd, MAXPATHLEN + 1)) == NULL)
	{
		ft_printf("%s: Error when getting current working directory\n",\
																	PROGNAME);
		sh_deinit(data);
		exit(1);
	}
	if (!(sh_getenv("TERM")) || ft_strequ(sh_getenv("TERM")->value, ""))
		sh_setenv("TERM", "xterm");
	if ((tgetent(0, sh_getenv_value("TERM"))) != 1)
	{
		ft_printf("%s: Error on tgetent\n", PROGNAME);
		sh_deinit(data);
		exit(1);
	}
	return (data);
}

void		sh_store_tattr(t_sh_data *data)
{
	int				ttydevice;
	struct termios	save_tattr;

	ttydevice = STDOUT_FILENO;
	if (tcgetattr(ttydevice, &save_tattr) != 0)
	{
		ft_printf("%s: tcgetattr error when trying", PROGNAME);
		ft_printf(" to save terminal attributes\n");
		return ;
	}
	else if ((data->tattr = (struct termios*)malloc(sizeof(struct termios))))
		ft_memcpy(data->tattr, &save_tattr, sizeof(struct termios));
	return ;
}
