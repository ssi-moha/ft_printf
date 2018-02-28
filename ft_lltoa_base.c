/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:31:32 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/12/29 19:21:50 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_size(long long value, int base)
{
	long i;

	i = 0;
	while (value >= base)
	{
		value /= base;
		i++;
	}
	return (i);
}

char				*ft_lltoa_base(long long value, int base)
{
	char		*tab;
	char		*str;
	long long	i;

	if (value == 0)
		return (ft_strdup("0"));
	tab = "0123456789abcdef";
	if (base < 2 != base > 16)
		return (NULL);
	if (base == 10)
		return (ft_lltoa(value));
	i = ft_size(value, base);
	if (!(str = ft_strnew(i)))
		return (NULL);
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i--] = tab[value % base];
		value /= base;
	}
	return (str);
}
