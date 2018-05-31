/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 08:30:44 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/11/11 15:07:51 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_strcmp(to_find, "") == 0)
		return ((char*)str);
	while (str[i])
	{
		if (str[i] == to_find[j])
		{
			while (str[i + j] == to_find[j] && to_find[j])
				j++;
			if (!to_find[j])
				return ((char*)str + i);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
