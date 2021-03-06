/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_help_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlasne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 15:19:22 by jlasne            #+#    #+#             */
/*   Updated: 2017/10/02 15:20:36 by jlasne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins/builtin_help.h>

/*
** @brief The function called when help is the next of sh_builtin_help()
**
** @param args The args passed to help
**
** @return Returns the ret value of help
*/

int		sh_builtin_help_helper(char **args)
{
	if (ft_strequ(args[1], "bonus"))
		sh_help_bonus(NULL, NULL);
	else if (ft_strequ(args[1], "history"))
		sh_help_history();
	else if (ft_strequ(args[1], "export"))
		sh_help_export();
	else if (ft_strequ(args[1], "chdir"))
		sh_help_chdir();
	else
	{
		ft_printf("%s: Couldn't find the help wanted for %s\n",\
		PROGNAME, args[1]);
		return (1);
	}
	return (0);
}

/*
** @brief The function display help history following the following
*/

void	sh_help_history_helper_helper(void)
{
	BOOL col;

	col = get_data(NULL)->opts.color;
	ft_printf("%s-s%s\n", (col) ? C_CYAN : "", C_NONE);
	ft_printf("\tThe args are added to the end of the history list as a single "
					"entry.\n");
	ft_printf("\n\t\tWhen any of the %s-w%s, %s-r%s, %s-a%s, or %s-n%s "
		"options is used, if filename is given, then it is used as the history "
			"file. If not, then the value of the HISTFILE variable is used.\n",
			(col) ? C_CYAN : "", C_NONE, (col) ? C_CYAN : "", C_NONE,
			(col) ? C_CYAN : "", C_NONE, (col) ? C_CYAN : "", C_NONE);
}

/*
** @brief The function display help history following
*/

void	sh_help_history_helper(void)
{
	BOOL col;

	col = get_data(NULL)->opts.color;
	ft_printf("\tAppend the new history lines to the history file. These are "
			"history lines entered since the beginning of the current shell "
				"session, but not already appended to the history file.\n");
	ft_printf("%s-n%s\n", (col) ? C_CYAN : "", C_NONE);
	ft_printf("\tAppend the history lines not already read from the history "
			"file to the current history list. These are lines appended to the "
			"history file since the beginning of the current shell session.\n");
	ft_printf("%s-r%s\n", (col) ? C_CYAN : "", C_NONE);
	ft_printf("\tRead the history file and append its contents to the "
															"history list.\n");
	ft_printf("%s-w%s\n", (col) ? C_CYAN : "", C_NONE);
	ft_printf("\tWrite out the current history list to the history file.\n");
	ft_printf("%s-p%s\n", (col) ? C_CYAN : "", C_NONE);
	ft_printf("\tPerform history substitution on the args and display the "
				"result on the standard output, without storing the results"
					" in the history list.\n");
	sh_help_history_helper_helper();
}

/*
** @brief The function display help pwd
*/

void	sh_help_pwd(void)
{
	BOOL col;

	col = get_data(NULL)->opts.color;
	ft_printf("%spwd%s [%s-L|-P%s] [directory]\n", (col) ? CL_RED : "", C_NONE,
												(col) ? C_CYAN : "", C_NONE);
	ft_printf("The pwd utility shall write to standard output an absolute "
			"pathname of the current working directory, which does not "
			"contain the filenames dot or dot-dot.\n");
	ft_printf("%s-L%s\tIf the %sPWD%s environment variable contains an absolute"
			" pathname of the current directory that does not contain the "
			"filenames dot or dot-dot, pwd shall write this pathname to "
			"standard output.\n\tOtherwise, the %s-L%s option shall behave as "
			"the %s-P%s option.\n", (col) ? C_CYAN : "", C_NONE,
			(col) ? C_GREEN : "", C_NONE, (col) ? C_CYAN : "", C_NONE,
			(col) ? C_CYAN : "", C_NONE);
	ft_printf("%s-P%s\tThe pathname written to standard output shall not "
			"contain any components that refer to files of type symbolic link. "
			"\n", (col) ? C_CYAN : "", C_NONE);
	ft_printf("If both %s-L%s and %s-P%s are specified, the last one shall "
			"apply. If neither %s-L%s nor %s-P%s is specified, the pwd utility "
			"shall behave as if %s-L%s had been specified.\n",
			(col) ? C_CYAN : "", C_NONE, (col) ? C_CYAN : "", C_NONE,
			(col) ? C_CYAN : "", C_NONE, (col) ? C_CYAN : "", C_NONE,
			(col) ? C_CYAN : "", C_NONE);
}

void	sh_help_export(void)
{
	BOOL col;

	col = get_data(NULL)->opts.color;
	ft_printf("%sexport%s [%s-n%s] [%sname%s[=%svalue%s] ...] or export "
			"%s-p%s\n", (col) ? CL_RED : "", C_NONE, (col) ? C_CYAN : "",
			C_NONE, (col) ? C_CYAN : "", C_NONE, (col) ? C_MAGENTA : "",
			C_NONE, (col) ? C_CYAN : "", C_NONE);
	ft_printf("\tSet export attribute for shell variables.\n");
	ft_printf("\tMarks each %sNAME%s for automatic export to the environment of"
			" subsequently\n", (col) ? C_CYAN : "", C_NONE);
	ft_printf("\texecuted commands.  If VALUE is supplied, assign VALUE before "
	"exporting.\n", (col) ? C_CYAN : "", C_NONE, (col) ? C_CYAN : "", C_NONE);
	ft_printf("\tOptions:\n");
	ft_printf("\t\t%s-f%s\trefer to shell functions\n", (col) ? C_CYAN : "",
			C_NONE);
	ft_printf("\t\t%s-n%s\tremove the export property from each %sNAME%s\n",
			(col) ? C_CYAN : "", C_NONE, (col) ? C_CYAN : "", C_NONE);
	ft_printf("\t\t%s-p%s\tdisplay a list of all exported variables\n",
			(col) ? C_CYAN : "", C_NONE);
	ft_printf("\tAn argument of `--' disables further option processing.\n");
	ft_printf("\tExit Status:\n");
	ft_printf("\t\tReturns success unless an invalid option is given or "
					"%sNAME%s is invalid.\n", (col) ? C_CYAN : "", C_NONE);
}
