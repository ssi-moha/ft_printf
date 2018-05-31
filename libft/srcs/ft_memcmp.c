/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 04:45:02 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/11/11 14:55:55 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*strs1;
	char	*strs2;
	size_t	i;

	strs1 = (char*)s1;
	strs2 = (char*)s2;
	i = 0;
	while (i < n)
	{
		if (strs1[i] != strs2[i])
			return ((unsigned char)strs1[i] - (unsigned char)strs2[i]);
		i++;
	}
	return (0);
}
