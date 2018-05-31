/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:02:22 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/12/02 15:14:32 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>
#include <stdio.h>

int		ft_size(int value, int base)
{
	int i;

	i = 0;
	while (value >= base)
	{
		value /= base;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa_base(int value, int base)
{
	char	*tab;
	char	*str;
	int		nb;
	int		i;

	tab = "0123456789abcdef";
	nb = value;
	i = 0;
	if (base < 2 != base > 16)
		return (NULL);
	if (base == 10)
		return (ft_itoa(value));
	if (!(str = ft_memalloc(sizeof(char) * ft_size(value, base))))
		return (NULL);
	while (value > 0)
	{
		str[i++] = tab[value % base];
		value /= base;
	}
	ft_strrev(str);
	return (str);
}
