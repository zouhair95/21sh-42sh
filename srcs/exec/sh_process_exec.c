/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_process_exec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:26:15 by chbravo-          #+#    #+#             */
/*   Updated: 2017/07/30 15:29:51 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <exec/exec.h>

/*void	lexer_print_type(t_token_type type)// inutile juste pour debug
{
	if (type == E_TOKEN_BLANK)
		ft_putstr("TOKEN_TYPE_BLANK");
	else if (type == E_TOKEN_NEWLINE)
		ft_putstr("TOKEN_TYPE_NEWLINE");
	else if (type == E_TOKEN_WORD)
		ft_putstr("TOKEN_TYPE_WORD");
	else if (type == E_TOKEN_SQUOTE)
		ft_putstr("TOKEN_TYPE_SQUOTE");
	else if (type == E_CHAR_TYPE_BQUOTE)
		ft_putstr("TOKEN_TYPE_BQUOTE");
	else if (type == E_TOKEN_DQUOTE)
		ft_putstr("TOKEN_TYPE_DQUOTE");
	else if (type == E_TOKEN_PIPE)
		ft_putstr("TOKEN_TYPE_PIPE");
	else if (type == E_TOKEN_OR_IF)
		ft_putstr("TOKEN_TYPE_OR_IF");
	else if (type == E_TOKEN_LESSGREAT)
		ft_putstr("TOKEN_TYPE_LESSGREAT");
	else if (type == E_TOKEN_DGREAT)
		ft_putstr("TOKEN_TYPE_DGREAT");
	else if (type == E_TOKEN_DLESS)
		ft_putstr("TOKEN_TYPE_DLESS");
	else if (type == E_TOKEN_AND)
		ft_putstr("TOKEN_TYPE_AND");
	else if (type == E_TOKEN_AND_IF)
		ft_putstr("TOKEN_TYPE_AND_IF");
	else if (type == E_TOKEN_SEMI)
		ft_putstr("TOKEN_TYPE_SEMI");
	else if (type == E_TOKEN_LESSAND)
		ft_putstr("TOKEN_TYPE_LESSAND");
	else if (type == E_TOKEN_GREATAND)
		ft_putstr("TOKEN_TYPE_GREATAND");
	else if (type == E_TOKEN_IO_NUMBER)
		ft_putstr("TOKEN_TYPE_IO_NUMBER");
}*/

int   sh_process_exec(t_sh_data *data, t_btree *ast)
{
  t_cmd *item;

  if (!ast)
    return (-1);
  item = (t_cmd *)ast->item;
  if (item->type == E_TOKEN_WORD)
    return (sh_exec_simple(data, item));
  else if (item->type == E_TOKEN_PIPE)
		return (sh_process_pipe(data, ast));
  else if(item->type == E_TOKEN_AND_IF)
    return((sh_process_exec(data, ast->left) == 0) && (sh_process_exec(data, ast->right) == 0));
	else if(item->type == E_TOKEN_OR_IF)
	  return((sh_process_exec(data, ast->left) == 0) || (sh_process_exec(data, ast->right) == 0));
	else if(item->type == E_TOKEN_SEMI)
	{
		sh_process_exec(data, ast->left);
		return (sh_process_exec(data, ast->right));
	}
	else if((item->type == E_TOKEN_LESSGREAT) || (item->type == E_TOKEN_DLESS ) ||\
	 			(item->type == E_TOKEN_DGREAT))
      return(sh_exec_redir(data, ast));
  else if(item->type == E_TOKEN_GREATAND)
    return(sh_exec_greatand(data, ast, item));
  //else if (item->type == E_TOKEN_GREATAND)
	//lexer_print_type(item->type); // POUR DEBUG
  return (ft_printf("\nERROR\n"));
}


/* ******* OLD ******** */

/*int	sh_command(t_sh_data *data, char **command)
{
	t_builtin	*e;
	char		**cmd;

	while (*command)
	{
		if ((e = get_builtin(*command)))
		{
			if (e->fn(data, *command + e->len + 1))
				return (1);
		}
		else
		{
			if ((cmd = sh_get_command(*command)))
				sh_exec_command(cmd);
		}
		command++;
	}
	return (0);
}

char **sh_get_command(char *input)
{
	return (ft_strsplit(input, ' '));
}

int	sh_exec_command(char **command)
{
	char	*cmd;
	char	**envtab;
	pid_t	pid;
	int		status;

	status = 0;
	envtab = sh_tenv_to_tab();
	if ((cmd = sh_check_path(command[0])))
	{
		if ((pid = fork()) == -1)
			ft_printf("fork error");
		else if (pid == 0)
		{
			execve(cmd, command, envtab);
			exit(0);
		}
		else
			wait(&status);
	}
	return (0);
}*/
