/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 07:57:52 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/02/12 13:01:02 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptrs;

	ptrs = (char*)s;
	i = 0;
	while (ptrs[i])
	{
		if (ptrs[i] == c)
			return (ptrs + i);
		i++;
	}
	if (ptrs[i] == c)
		return (ptrs + i);
	return (NULL);
}
