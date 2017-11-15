/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 20:31:43 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/21 13:03:18 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <array/array.h>
# include <btree/ft_btree.h>

/*
** @file   main.h
**
** @brief  Includes everything needed in the main()
**
** This contains the prototypes for the program,
** and eventually any macros, constants,
** or global variables you will need.
*/

/*
** @file main.c
**
** @brief Contains the main function
*/

struct			s_exec_data
{
	t_array		tokens;
	t_array		expand;
	t_btree		*ast;
};

#endif
