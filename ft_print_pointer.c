/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 10:56:21 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/12/29 09:32:13 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		make_width(char *arg, t_print *option, char **ret)
{
	int		size;
	char	*add;

	size = option->width - ft_strlen(*ret);
	add = ft_strnew(size + 1);
	add = ft_memset(add, ' ', size);
	if (option->minus)
		*ret = ft_strjoin(*ret, add);
	else
		*ret = ft_strjoin(add, *ret);
}

char			*ft_print_pointer(va_list params, t_print *option)
{
	char	*ret;
	char	*arg;
	int		len;

	option->mod = ft_strdup("ll");
	arg = modif_arguns(params, option, 16);
	len = ft_strlen(arg) + 3;
	ret = ft_strnew(len + 3);
	ret = ft_strcat(ft_strdup("0x"), arg);
	if (option->width > ft_strlen(ret))
		make_width(arg, option, &ret);
	return (ret);
}
