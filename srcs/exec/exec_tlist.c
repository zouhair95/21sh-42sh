/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 18:45:10 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/13 19:50:04 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec/exec.h>

void	exec_list_push(t_list **head, size_t fd)
{
	t_list	*elem;

	elem = (t_list *)ft_memalloc(sizeof(t_list));
	if (!elem)
		return ;
	elem->content = NULL;
	elem->content_size = fd;
	elem->next = NULL;
	ft_lstpush_back(head, elem);
}

void	exec_list_nothing(void *no, size_t thing)
{
	(void)no;
	(void)thing;
}
