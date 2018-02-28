/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:29:22 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/12/29 17:07:44 by ssi-moha         ###   ########.fr       */
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
	return (i + 1);
}

char				*ft_ulltoa_base(unsigned long long value, int base)
{
	char				*tab;
	char				*str;
	unsigned long long	i;

	if (value == 0)
		return (ft_strdup("0"));
	tab = "0123456789abcdef";
	i = 0;
	if (base < 2 != base > 16)
		return (NULL);
	if (base == 10)
		return (ft_ulltoa(value));
	if (!(str = ft_strnew(ft_size(value, base))))
		return (NULL);
	while (value > 0)
	{
		str[i++] = tab[value % base];
		value /= base;
	}
	ft_strrev(str);
	return (str);
}
