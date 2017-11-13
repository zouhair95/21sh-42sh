/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_environ_env.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/03 18:21:50 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/02 14:33:52 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <array/array.h>
#include <environ/env_utils.h>
#include <unistd/ft_unistd.h>
#include <ftprintf.h>
#include <builtins/builtin_env.h>

extern int g_optind;

int		builtins_env_over(t_array *env_local, int ret)
{
	array_destroy(&env_local, del_env);//(void (*)(void*))&sh_free_elem_env);
	return (ret);
}

int		builtin_env_opt(char **argv)
{
	int opt;
	int tmp;

	ft_getopt_reset();
	tmp = 0;
	while ((opt = ft_getopt(ft_tablen(argv), argv, "ui")) != -1)
	{
		if (opt == 'u')
			break ;
		else if (opt == '?')
			break ;
		else if (opt == 'i')
			tmp = opt;
	}
	if (opt == 'u' && g_optind != -1 && !argv[g_optind])
	{
		ft_dprintf(2, "env: option requires an argument -- 'u'\n");
		opt = -1;
	}
	else if (tmp == 'i' && opt != 'u')
		opt = 'i';
	else if (opt == '?')
		opt = -1;
	return (opt);
}

t_array	*sh_get_env_builtins(int opt, char **argv)
{
	t_array *tmp;

	if ((tmp = array_create(sizeof(t_env))) == NULL)
	{
		ft_dprintf(STDERR_FILENO, "Environ: can't initialise local environment\
				variables\n");
		exit(1);
	}
	if (opt == 'i')
		return (sh_builtin_env_add(tmp, argv));
	else if (opt == 'u')
		return (sh_builtin_env_u(tmp, argv));
	else
		return (sh_builtin_env_add(clone_vars(get_envs(), tmp), argv));
}

int		sh_builtin_env(t_sh_data *data, char **argv)
{
	int		opt;
	t_array *env_local;

	(void)data;
	if (!argv[1])
	{
		print_vars(get_envs());
		return (0);
	}
	opt = builtin_env_opt(argv);
	if (!(env_local = sh_get_env_builtins(opt, argv)))
		return (1);
	if (g_optind != -1 && sh_builtin_env_exec(&argv[g_optind], env_local))
		return (builtins_env_over(env_local, 1));
	if (g_optind != -1 && !argv[g_optind])
		print_vars(env_local);
	ft_getopt_reset();
	return (builtins_env_over(env_local, 0));
}
