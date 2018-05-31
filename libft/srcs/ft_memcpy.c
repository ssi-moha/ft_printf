/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:05:17 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/11/11 14:56:14 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *strdst;
	char *strsrc;

	strdst = (char*)dst;
	strsrc = (char*)src;
	while (n > 0)
	{
		*strdst++ = *strsrc++;
		n--;
	}
	return (dst);
}
