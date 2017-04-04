/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 09:43:16 by jlasne            #+#    #+#             */
/*   Updated: 2017/03/21 10:25:12 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser/parser.h>

t_bool gr_io_redirect(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	log_info("Parser is at gr_io_redirect.");
	if ((gr_io_file(tokens, where) == true) || \
	((tok->type == E_TOKEN_IO_NUMBER) && \
	gr_io_file(tokens, where) == true) || \
	(gr_io_here(tokens, where) == true) || \
	((tok->type == E_TOKEN_IO_NUMBER) && \
	gr_io_here(tokens, where) == true))
	{
		log_dbg3("Parser returned true at gr_io_redirect.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_io_redirect.");
		return false;
	}
	//TODO, add check for pipe and stuff as for the rest
}

t_bool gr_io_file(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	log_info("Parser is at gr_io_file.");
	if (((tok->str[0] == '<') && gr_filename(tokens, where) == true) || \
	((tok->type == E_TOKEN_LESSAND) && (gr_filename(tokens, where) == true)) || \
	(((tok->str[0] == '>') && gr_filename(tokens, where) == true)) || \
	((tok->type == E_TOKEN_GREATAND) && (gr_filename(tokens, where) == true)) || \
	((tok->type == E_TOKEN_DGREAT) && (gr_filename(tokens, where) == true)) || \
	((tok->type == E_TOKEN_LESSGREAT) && (gr_filename(tokens, where) == true)))
	{
		log_dbg3("Parser returned true at gr_io_file.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_io_file.");
		return false;
	}
	//TODO, add check for pipe and stuff as for the rest
}


t_bool gr_io_here(t_array *tokens, size_t where) {
	t_token *tok;

	tok = (t_token *) array_get_at(tokens, where);
	log_info("Parser is at gr_io_here.");
	if ((tok->type == E_TOKEN_DLESS) && (gr_here_end(tokens, where) == true)) {
		log_dbg3("Parser returned true at gr_io_here.");
		return true;
	} else {
		log_dbg3("Parser returned false at gr_io_here.");
		return false;
	}
}

t_bool gr_filename(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	log_info("Parser is at gr_filename.");
	if (tok->type == E_TOKEN_WORD) //TODO, add check for pipe and stuff as for the rest
	{
		log_dbg3("Parser returned true at gr_filename.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_filename.");
		return false;
	}
}

t_bool gr_here_end(t_array *tokens, size_t where)
{
	t_token *tok;

	tok = (t_token *)array_get_at(tokens, where);
	log_info("Parser is at gr_here_end.");
	if (tok->type == E_TOKEN_WORD) //TODO, add check for pipe and stuff as for the rest
	{
		log_dbg3("Parser returned true at gr_here_end.");
		return true;
	}
	else
	{
		log_dbg3("Parser returned false at gr_here_end.");
		return false;
	}
}