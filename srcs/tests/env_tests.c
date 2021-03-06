/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 09:27:49 by chbravo-          #+#    #+#             */
/*   Updated: 2017/05/30 14:26:11 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tests/sh_tests.h>

/*
** @brief Function to test the set module for the env
**
** @param av The arguments passsed to the test module
*/

void	sh_testing_env_set(char *const *av)
{
	int		i;
	char	*name;
	char	*value;

	i = 1;
	while (av[i] && ft_strchr(av[i], '='))
	{
		name = split_var_name(av[i]);
		value = split_var_value(av[i]);
		set_var(get_envs(), name, value, true);
		ft_strdel(&name);
		ft_strdel(&value);
		i++;
	}
}

/*
** @brief Function to test the del function for the env
**
** @param av The arguments passsed to the test module
*/

void	sh_testing_env_del(char *const *av)
{
	int		i;

	i = 1;
	while (av[i])
	{
		del_var(get_envs(), av[i]);
		i++;
	}
}

/*
** @brief Main funtion used to test the env module
**
** @param av The arguments passed to the test module
** @param environ The current environ
*/

void	sh_testing_env(char *const *av, char **environ)
{
	if (ft_strlen(av[0]) >= MAX_LEN_INPUT)
		sh_exit_printf("line is too long: %zu, MAX is %zu", ft_strlen(av[0]),
					MAX_LEN_INPUT);
	else if (ft_strlen(av[0]) && !is_printstr(av[0]))
		sh_exit_printf("line: contains non-ascii characters.");
	init_environ(environ);
	if (av[0] && (ft_strequ(av[0], "set")))
		sh_testing_env_set(av);
	else if (av[0] && (ft_strequ(av[0], "del")))
		sh_testing_env_del(av);
	print_vars(get_envs(), true);
	exit(0);
}
