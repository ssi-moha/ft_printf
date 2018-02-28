/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   det_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:16:43 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/12/29 18:20:50 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_len(char *arg, t_print *option)
{
	int i;
	int arglen;

	i = 0;
	arglen = ft_strlen(arg);
	if (option->prc >= option->width && option->prc > arglen)
		i = option->prc;
	else if (option->width && option->width > arglen)
		i = option->width;
	else
	{
		i = arglen;
		option->width = 0;
	}
	if (option->space || option->plus)
		i++;
	return (i);
}
