/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 04:24:03 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/11/11 14:55:29 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char *strs;

	strs = (char*)s;
	while (n--)
	{
		if (*strs == (char)c)
			return (strs);
		strs++;
	}
	return (NULL);
}
