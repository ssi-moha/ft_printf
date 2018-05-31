/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 08:07:06 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/11/11 14:59:06 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_affi(int n)
{
	if (n < 10)
	{
		ft_putchar(n + 48);
		return (0);
	}
	else
	{
		ft_affi(n / 10);
		ft_putchar(n % 10 + 48);
	}
	return (0);
}

void			ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		ft_putchar('-');
		ft_affi(-n);
	}
	else
		ft_affi(n);
}
