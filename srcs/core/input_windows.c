/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_windows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:00:24 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/17 14:08:48 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/input.h>
#include <tools/tools.h>

/*
** @brief Helper for get_windows
**
** @param wd widow data
** @param rst  the reset byte
**
** @return window data
*/

static t_window		*get_windows2(t_window *wd, int rst)
{
	if ((rst %= 10) && rst >= 4)
	{
		ft_strdel(&wd->select.str);
		ft_bzero((void *)&wd->select, sizeof(wd->select));
	}
	if ((rst %= 4) && rst >= 2)
		wd->h_lvl = -1;
	if ((rst %= 2) && rst == 1)
		ioctl(STDIN_FILENO, TIOCGWINSZ, &wd->ts);
	return (wd);
}

/*
** @brief		Create and manage windows data
**
** @param[in]	rst		the reset byte
**
** @details		rst can be a byte or an addition of byte like that
** 				100 reset autocomple select data
**				40	reset history complet
** 				20	hard reset current input
** 				10	destroy saved input
** 				4	reset the selection data
** 				2	reset history level
** 				1	reset windows size
** 				example:
** 				to reset current and save input and history level:
** 				rst = 32 = 20 + 10 + 2
** 				to reset everything:
** 				rst = 37 = 20 + 10 + 4 + 2 + 1
** @return Returns the t_window struct
*/

t_window			*get_windows(int rst)
{
	static	t_window	*wd = NULL;

	if (wd && !rst)
		return (wd);
	if (!(wd))
	{
		if (!(wd = ft_memalloc(sizeof(*wd))))
			sh_exit_error("Malloc Error");
		rst = 77;
	}
	if (rst >= 100)
		select_deinit(&wd->autocomp, true);
	if ((rst %= 100) && rst >= 40)
		wd->h_complet = false;
	if ((rst %= 40) && rst >= 20)
	{
		get_select()->is = false;
		if (!(input_hard_reset(&wd->cur_head)))
			sh_exit_error("Error Malloc hard reset");
	}
	if ((rst %= 20) && rst >= 10)
		input_destroy(&wd->save);
	return (get_windows2(wd, rst));
}

/*
** @brief Moves the current input to the `dest_inp` destination input
**
** @param input The current input
** @param dest_inp The destination of the current input
**
** @return Return the changed and moved input
*/

t_input				*goto_input(t_input *input, t_input *dest_inp)
{
	t_cpos	dest;

	while (input && input != dest_inp)
	{
		dest = input_get_first_pos(input);
		move_cursor_to(&dest, &input->cpos, get_ts());
		if (input->next)
			tputs(tgetstr("do", NULL), 0, &ft_putc_in);
		else
			break ;
		input = input->next;
	}
	return (input);
}
