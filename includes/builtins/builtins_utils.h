/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:58:45 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/17 15:46:42 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUILTINS_UTILS_H
# define BUILTINS_UTILS_H
#include "exit.h"

typedef 	int (*t_builtin)(char *arg);

typedef struct			s_builtin_e
{
	struct s_builtin_e	*next;
	t_builtin			fn;
	char				*name;
}						t_builtin_e;

t_builtin_e				*ms_builtins_init(void);
t_builtin				ms_is_builtin(t_builtin_e *head, char *name);

#endif