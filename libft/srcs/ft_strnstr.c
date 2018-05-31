/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:56:42 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/11/11 15:06:48 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *to_find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (ft_strcmp(to_find, "") == 0)
		return ((char*)src);
	while (src[i] && i < len)
	{
		if (src[i] == to_find[j])
		{
			while (src[i + j] == to_find[j] && to_find[j] && j + i < len)
				j++;
			if (!to_find[j])
				return ((char*)src + i);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
