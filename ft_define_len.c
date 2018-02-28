/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 05:52:04 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/12/29 09:23:06 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_define_len(char *arg, t_print *option)
{
	int len;

	if (option->prc > 0 && option->prc >= option->width && option->prc >=
			ft_strlen(arg))
		len = option->prc;
	else if (option->width && option->width >= ft_strlen(arg))
		len = option->width;
	else
	{
		len = ft_strlen(arg);
		option->width = 0;
		if (option->prc != 0)
			option->prc = -1;
	}
	if (option->space)
	{
		if (arg[0] == '-')
			len += 2;
		else
			len++;
	}
	else if (option->plus)
		len++;
	return (len);
}
