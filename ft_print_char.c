/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:46:49 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/12/29 09:27:07 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_char(va_list params, t_print *option)
{
	char	*ret;
	char	arg;
	int		i;

	i = 0;
	if (option->type == 14)
		arg = '%';
	else
		arg = va_arg(params, int);
	ret = ft_memalloc(sizeof(char) * option->width + 2);
	if (arg == '\0')
		ret[0] = '0';
	else
		ret[0] = arg;
	if (option->width)
		handle_width(&ret, option);
	option->len = ft_strlen(ret);
	while (i < option->len && arg == '\0')
	{
		if (ret[i] == '0')
			ret[i] = '\0';
		i++;
	}
	return (ret);
}
