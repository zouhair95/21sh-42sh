/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 19:36:55 by chbravo-          #+#    #+#             */
/*   Updated: 2017/01/16 11:27:09 by chbravo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "main.h"

int main(int ac, char const *av[])
{
	t_main_data	*data;

	if (!ac || !av)
		return (1);
	if (!(data = init()))
		return (1);
	cbc_print_prompt();
	return (0);
}