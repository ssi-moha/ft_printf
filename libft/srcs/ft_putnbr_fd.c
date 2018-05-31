/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 08:30:07 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/11/11 14:59:18 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_affi(int n, int fd)
{
	if (n < 10)
	{
		ft_putchar_fd(n + 48, fd);
		return (0);
	}
	else
	{
		ft_affi(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
	return (0);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_affi(-n, fd);
	}
	else
		ft_affi(n, fd);
}
