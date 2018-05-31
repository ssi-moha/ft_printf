/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:07:50 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/11/12 04:17:21 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*strdst;
	char	*strsrc;
	size_t	i;

	strdst = (char*)dst;
	strsrc = (char*)src;
	i = 0;
	if (n == 0)
		return (NULL);
	while (n--)
	{
		strdst[i] = strsrc[i];
		if (((unsigned char*)strsrc)[i] == (unsigned char)c)
		{
			i++;
			return ((unsigned char*)strdst + i);
		}
		i++;
	}
	return (NULL);
}
