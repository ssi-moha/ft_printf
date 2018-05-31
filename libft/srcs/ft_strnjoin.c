/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 15:01:47 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/12/28 15:53:50 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	char	*join;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (join == NULL)
		return (NULL);
	while (*s1)
	{
		join[i++] = *s1++;
	}
	while (n--)
	{
		join[i++] = *s2++;
	}
	join[i] = '\0';
	return (join);
}
