/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:36:55 by chbravo-          #+#    #+#             */
/*   Updated: 2017/06/03 18:23:12 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core/main.h>

int main(int ac, char *const *av)
{

	t_sh_data	data;
	t_automaton	automaton;
	t_array		tokens;
	char		*input;
	BOOL		stop;

	/*sh_init_environ();
	char *tmp = sh_getenv_value("LSCOLORS");
	ft_printf("%s",tmp);*/
	if (!sh_init(&data, ac, av))
		exit(1);
	if (lexer_init(&tokens) == NULL)
		exit (1);
	if (automaton_init(&automaton) == NULL)
		exit (1);
	stop = true;
	while (stop == true)
	{
		sh_print_prompt();
		input = sh_get_line();
		if (lexer_lex(&tokens, &automaton, input))
			if (parser_parse(&tokens))
				ft_printf("exec\n");
		sh_history_set_new(input);
		// if ((command = ft_strsplit(input, ';')))
		// 	if (sh_command(data, command))
		// 		stop = true;
		if (input && ft_strequ(input, "exit"))
			stop = false;
		input ? ft_strdel(&input) : 0;
		array_reset(&tokens, NULL);
		automaton_reset(&automaton);
	}
	sh_history_save();
	sh_deinit(&data);
	ft_putstr("\033[?1049l");
	return (0);
}
