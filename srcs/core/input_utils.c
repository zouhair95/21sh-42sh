/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 22:24:50 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/02 15:43:55 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/input.h>

/*
** @brief Destroys the given input
**
** @param input The input to be destroyed
*/

void	input_destroy(t_input **input)
{
	if (*input)
	{
		if ((*input)->next)
			input_destroy(&(*input)->next);
		if ((*input)->str)
			string_del(&((*input)->str));
		ft_memdel((void **)input);
	}
}

/*
** @brief Resets the given input
**
** @param input The input to be reset
*/

void	input_reset(t_input *input)
{
	if (input->str)
		string_reset(input->str);
	else
		input->str = string_create();
	input->prompt_len = 0;
	input->offset_col = 0;
	input->cpos.cp_line = 0;
	input->cpos.cp_col = 0;
	input->lock = false;
	input->select_pos.is_set = false;
	input->select_pos.cur_end = 0;
	input->select_pos.cur_start = 0;
}

/*
** @brief Gets the pos in the string
**
** @param input The current input
**
** @return Returns the position
*/

size_t	pos_in_str(t_input *input)
{
	size_t			ret;
	struct winsize	*ts;

	ts = get_ts();
	ret = (input->cpos.cp_col - input->offset_col)
		+ (input->cpos.cp_line * ts->ws_col);
	return (ret);
}

/*
** @brief gets the first input not lock
**
** @param input current input
**
** @return the first input not lock
*/

t_input	*input_get_writable(t_input *input)
{
	while (input && input->prev && !input->prev->lock)
		input = input->prev;
	return (input);
}
