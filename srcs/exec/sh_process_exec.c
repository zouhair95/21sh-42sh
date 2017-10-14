/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_process_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:26:15 by chbravo-          #+#    #+#             */
/*   Updated: 2017/10/14 12:51:42 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <exec/exec.h>

t_cmd *init_exec(t_btree *ast, t_array **fds)
{
	int		fd[3];

	fd[0] = STDIN_FILENO;
	fd[1] = STDOUT_FILENO;
	fd[2] = STDERR_FILENO;
	if (!ast)
		return (NULL);
	*fds = array_create(sizeof(fd));
	*fds = array_push(*fds, fd);
	*fds = array_push(*fds, fd);
	if (!*fds)
		return (NULL);
	return ((t_cmd *)ast->item);
}

/*
 ** @brief         handle ast before exec
 **                it is recurcive function
 **                fisrt is ast->left (branch left of binary tree AST)
 **                if it is WORD so execute "normal"
 **                if OR it is: "normal" OR "normal"
 **                etc
 **
 ** @param  data    The data of shell
 ** @param  ast     The AST (Analyse Syntax Tree[binary])
 **
 ** @return     -1 on error or unknow TOKEN
 */

int   sh_process_exec(t_sh_data *data, t_btree *ast, t_list *fds[4])
{
	t_cmd	*item;

	if (!ast)
		return (-1);
	item = (t_cmd *)ast->item;
	if (item->type == E_TOKEN_WORD)
		return (sh_exec_simple(data, item, fds));
	else if(item->type == E_TOKEN_SEMI)
	{
		sh_process_exec(data, ast->left, fds);
		return (sh_process_exec(data, ast->right, fds));
	}
	else if(item->type == E_TOKEN_AND_IF)
		return((sh_process_exec(data, ast->left, fds) == 0) &&\
				(sh_process_exec(data, ast->right, fds) == 0));
	else if(item->type == E_TOKEN_OR_IF)
		return((sh_process_exec(data, ast->left, fds) == 0) ||\
			(sh_process_exec(data, ast->right, fds) == 0));
	else if((item->type == E_TOKEN_LESSGREAT) || (item->type == E_TOKEN_DLESS ) ||\
			(item->type == E_TOKEN_DGREAT))
			return(sh_exec_redir(data, ast, item, fds));
	/*else if (item->type == E_TOKEN_PIPE)
		return (sh_process_pipe(data, ast));


	else if(item->type == E_TOKEN_GREATAND)
		return(sh_exec_greatand(data, ast, item));*/
	return (-1);
}

int		exec_exec(t_sh_data *data, t_btree *ast)
{
	t_list	*fds[4];

		if (!ast)
			return (-1);
	fds[0] = NULL;
	fds[1] = NULL;
	fds[2] = NULL;
	fds[3] = NULL;
	return (sh_process_exec(data, ast, fds));
}
