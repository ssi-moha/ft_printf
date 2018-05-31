/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:30:13 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/11/11 14:56:55 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (dst >= (void*)src)
		while (len)
		{
			((char*)dst)[len - 1] = ((char*)src)[len - 1];
			len--;
		}
	else
		while (i < len)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i++;
		}
	return (dst);
}
