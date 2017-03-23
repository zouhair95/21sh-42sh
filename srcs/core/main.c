/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:36:55 by chbravo-          #+#    #+#             */
/*   Updated: 2017/03/04 07:14:37 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <core/main.h>


int main(int ac, char *const *av)
{
	t_ms_data	data;
	char		*input;
	BOOL		stop;
	t_array		*tokens;

	if (!ms_init(&data, ac, av))
		exit(1);
	stop = true;
	while (stop == true)
	{
		ms_print_prompt();
		input = ms_get_line();
		tokens = lexer_lex(input);
		if (tokens)
			lexer_print_tokens(tokens);
		// if ((command = ft_strsplit(input, ';')))
		// 	if (ms_command(data, command))
		// 		stop = true;
	}
	ms_deinit(&data);
	return (0);
}
