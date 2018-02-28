/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:05:42 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/12/29 17:00:16 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_width(char **ret, t_print *option)
{
	char	*add;
	int		len;
	char	*tmp;
	char	c;

	if (option->zero == 1)
		c = '0';
	else
		c = ' ';
	len = ft_strlen(*ret);
	if (option->width <= len)
		return ;
	add = ft_strnew(option->width - len);
	add = ft_memset(add, c, option->width - len);
	if (option->minus)
	{
		*ret = ft_strcat(*ret, add);
		free(add);
	}
	else
	{
		tmp = *ret;
		*ret = ft_strcat(add, *ret);
		free(tmp);
	}
}
