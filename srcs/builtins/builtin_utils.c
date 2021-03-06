/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:58:16 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/02 15:04:14 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_utils.h>

/*
** @brief Gets all the builtins in a t_array
**
** @return Returns the t_array list of builtins
*/

t_array		*get_builtins(void)
{
	static t_array	*e = NULL;

	if (e == NULL)
	{
		if ((e = array_create(sizeof(t_builtin))) == NULL)
		{
			log_fatal("Builtins: Can't initialise builtins array");
			ft_dprintf(STDERR_FILENO, "Builtins: Can't initialize Builtins");
			exit(EXIT_FAILURE);
		}
	}
	return (e);
}

/*
** @brief Creates a new builtin in the array
**
** @param name The builtin name
** @param fn The builtins function
**
** @return The builtin array
*/

t_builtin	*sh_new_builtin(char *name, t_builtin_fn fn)
{
	t_builtin	*e;

	if (!(e = ft_memalloc(sizeof(*e))))
	{
		sh_exit_error("ERROR MALLOC Builtin creation fail!");
		return (NULL);
	}
	(void)name;
	e->name = ft_strdup(name);
	e->len = ft_strlen(name);
	e->fn = fn;
	return (e);
}

/*
** @brief Adds a new builtin in the array
**
** @param name The builtin name
** @param fn The builtins function
**
** @return The builtin array
*/

t_array		*sh_add_builtin(char *name, t_builtin_fn fn)
{
	t_array		*builtins;
	t_builtin	*builtin;

	builtins = get_builtins();
	builtin = sh_new_builtin(name, fn);
	array_push(builtins, (void *)builtin);
	ft_memdel((void **)&builtin);
	return (builtins);
}

/*
** @brief Initializes all the builtins and adds them to the array
**
** @return Returns the builtin array
*/

t_array		*sh_builtins_init_helper(t_array *builtins)
{
	if (!sh_add_builtin("env", sh_builtin_env))
		return (NULL);
	if (!sh_add_builtin("unset", builtin_unset))
		return (NULL);
	if (!sh_add_builtin("export", builtin_export))
		return (NULL);
	if (!sh_add_builtin("exit", builtin_exit))
		return (NULL);
	if (!sh_add_builtin("bonus", sh_help_bonus))
		return (NULL);
	return (builtins);
}

t_array		*sh_builtins_init(void)
{
	t_array	*builtins;

	builtins = get_builtins();
	if (!sh_add_builtin("echo", sh_echo))
		return (NULL);
	if (!sh_add_builtin("history", sh_history))
		return (NULL);
	if (!sh_add_builtin("cd", sh_chdir))
		return (NULL);
	if (!sh_add_builtin("chdir", sh_chdir))
		return (NULL);
	if (!sh_add_builtin("pwd", sh_builtin_pwd))
		return (NULL);
	if (!sh_add_builtin("help", sh_builtin_help))
		return (NULL);
	if (!sh_add_builtin("setenv", sh_builtin_setenv))
		return (NULL);
	if (!sh_add_builtin("unsetenv", sh_builtin_unsetenv))
		return (NULL);
	return (sh_builtins_init_helper(builtins));
}
