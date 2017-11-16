/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_dup_secu.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbravo- <chbravo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 01:09:53 by chbravo-          #+#    #+#             */
/*   Updated: 2017/09/16 17:00:20 by gpouyat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <secure_memory/secure_memory.h>

/**
 * @brief Securely duplicates a t_string
 *
 * @param str t_string to duplicate
 * @param lvl TODO
 *
 * @return Returns the duplicated t_string
 */

t_string	*string_dup_secu(const char *str, size_t lvl)
{
	if (!str)
		return (string_create_secu(lvl));
	return (string_ndup_secu(str, ft_strlen(str), lvl));
}

/**
 * @brief Duplicated a t_string until index `n` is reached
 *
 * @param str t_string to be duplicated
 * @param n Index to where to stop
 * @param lvl TODO
 *
 * @return Returns the duplicated t_string
 */

t_string	*string_ndup_secu(const char *str, size_t n, size_t lvl)
{
	t_string	*string;
	size_t		strlen;

	if (!str)
		return (string_create_cap_secu(n, lvl));
	strlen = ft_strlen(str);
	if (!(string = string_create_cap_secu(n, lvl)))
		return (NULL);
	ft_memcpy(string->s, str, (n > strlen) ? strlen : n);
	string->len = (n > strlen) ? strlen : n;
	return (string);
}
