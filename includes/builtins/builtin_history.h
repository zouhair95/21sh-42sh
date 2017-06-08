/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 10:54:13 by gpouyat           #+#    #+#             */
/*   Updated: 2017/06/08 14:29:39 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_HISTORY_H
#define BUILTIN_HISTORY_H

# include <history/history.h>
# include <core/data.h>


int		sh_history(t_sh_data *data, char **arg);
void	sh_history_builtin_a(char *str);
#endif
