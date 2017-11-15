/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 15:30:45 by gpouyat           #+#    #+#             */
/*   Updated: 2017/11/15 19:21:36 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec/exec.h>

BOOL			check_fd(int fd)
{
	if (fd <= STDERR_FILENO && fd >= 0)
		return (true);
	ft_dprintf(2, "%s: '%d' ONLY stdin (0), stdout (1), stderr (2) -- file"
			"descriptor files\n", PROGNAME, fd);
	return (false);
}

static int		here_find_fd(t_cmd *item)
{
	int		fd;

	fd = atoi(item->av[0]);
	if (ft_isdigit(item->av[0][0]))
	{
		if (fd <= STDERR_FILENO && fd >= 0)
			return (fd);
		else
		{
			ft_dprintf(2, "%s: '%d' ONLY 0, 1 or 2 number\n", PROGNAME,
					fd);
			return (-1);
		}
	}
	return (STDOUT_FILENO);
}

int				sh_open_exec(t_btree *ast)
{
	t_cmd	*item;
	int		fd;
	int		pos;

	if (!ast && ast->right)
		return (-1);
	item = (t_cmd *)ast->item;
	pos = 0;
	fd = -1;
	if (!item || ft_tablen(item->av) < 2)
		return (fd);
	if (ft_isdigit(item->av[0][0]))
		pos++;
	if (item->type == E_TOKEN_LESSGREAT && ft_strequ(item->av[pos], ">"))
		fd = open(item->av[pos + 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	else if (item->type == E_TOKEN_LESSGREAT)
		fd = open(item->av[pos + 1], O_RDWR, 0644);
	else if (item->type == E_TOKEN_DGREAT)
		fd = open(item->av[pos + 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	else if (item->type == E_TOKEN_DLESS)
		fd = here_find_fd(item);
	if (fd == -1)
		ft_dprintf(2, "%s: no such file or directory: %s\n", PROGNAME,
				item->av[pos + 1]);
	return (fd);
}
