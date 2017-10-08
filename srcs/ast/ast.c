/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 09:47:39 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/07 20:04:29 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast/ast.h>

/**
 * \fn t_btree	*ast_create(t_array *expands)
 *
 * \brief create ast
 *
 * \param expands is token arrays
 *
 * \return ast.
 */
t_btree	*ast_create(t_array *expands)
{
	t_lim		lim;
	t_btree		*ast;

	ast = NULL;
	lim.cnt = 0;
	lim.lim = 10000;
	ast = ast_built(ast, expands, lim, 1);
	log_dbg1("Ast created.");
	return (ast);
}
