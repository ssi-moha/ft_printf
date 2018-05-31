/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 08:12:38 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/11/11 15:07:02 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*ptrs;

	i = 0;
	j = -1;
	ptrs = (char*)s;
	while (ptrs[i])
	{
		if (ptrs[i] == c)
			j = i;
		i++;
	}
	if (ptrs[i] == c)
		j = i;
	if (j > -1)
		return (ptrs + j);
	else
		return (NULL);
}
