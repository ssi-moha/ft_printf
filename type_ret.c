/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_ret.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:25:14 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/12/29 17:09:08 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_ret(t_print *option, va_list params)
{
	static char *(*tab[15])(va_list, t_print *);
	char		*str;

	if (option->type == 1 || option->type == 13)
	{
		va_arg(params, char*);
		return (ft_strdup("DSL"));
	}
	if (option->type == -1)
		return (NULL);
	tab[0] = ft_print_string;
	tab[2] = ft_print_pointer;
	tab[3] = ft_print_int;
	tab[4] = ft_print_int;
	tab[5] = ft_print_int;
	tab[6] = ft_print_oct;
	tab[7] = ft_print_oct;
	tab[8] = ft_print_uns;
	tab[9] = ft_print_uns;
	tab[10] = ft_print_hex;
	tab[11] = ft_print_hex;
	tab[12] = ft_print_char;
	tab[14] = ft_print_char;
	str = tab[option->type](params, option);
	return (str);
}
