/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpouyat <gpouyat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 15:30:45 by gpouyat           #+#    #+#             */
/*   Updated: 2017/10/14 15:03:46 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <tools/tools.h>
# include <ast/ast.h>

int	sh_open_exec(t_btree *ast)
{
  t_cmd *item;
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
		fd = open(item->av[pos + 1], O_RDWR | O_CREAT, 0644);
	return (fd);
}

/*int sh_open_exec(t_btree *ast)
{
  t_cmd *item;
  t_cmd	*redir;
  int		fd;

  fd = -1;
  if (!ast && ast->right)
    return (-1);
  item = (t_cmd *)ast->right->item;
  redir = (t_cmd *)ast->item;

  if (redir->type == E_TOKEN_LESSGREAT && ft_strequ(redir->av[0], ">"))
    fd = open(redir->av[1], O_RDWR | O_CREAT, 0644);
  else if (redir->type == E_TOKEN_LESSGREAT)
    fd = open(item->av[0], O_RDWR, 0644);
  else if ((redir->type == E_TOKEN_DLESS ) || (redir->type == E_TOKEN_DGREAT))
    fd = open(item->av[0], O_RDWR | O_CREAT | O_APPEND, 0644);
  if (fd == -1)
    ft_dprintf(2, "Error: to open file: %s\n", item->av[0]);
  return (fd);
}*/


int   sh_open(char *file, int flags)
{
  int fd;

  fd = -1;
  if ((fd = open(file, flags, 0644)) == -1)
    ft_dprintf(2, "Error: to open file: %s\n", file);
  return (fd);
}
