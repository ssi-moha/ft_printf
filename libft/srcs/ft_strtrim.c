/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:05:19 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/11/11 15:09:09 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_i(const char *s)
{
	int i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	return (i);
}

static int		ft_j(const char *s)
{
	int j;

	j = ft_strlen(s);
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t' || s[j] == '\0')
			&& j > 0)
		j--;
	return (j);
}

char			*ft_strtrim(char const *s)
{
	char	*trim;
	int		i;
	int		j;
	int		k;

	k = 0;
	if (!s)
		return (NULL);
	i = ft_i(s);
	j = ft_j(s);
	trim = (char*)malloc(sizeof(char) * (j + 1));
	if (trim == NULL)
		return (NULL);
	if (s[i] == '\0')
	{
		trim[0] = '\0';
		return (trim);
	}
	if (i >= j)
		return (trim);
	while (i < j)
		trim[k++] = s[i++];
	trim[k++] = s[i];
	trim[k] = '\0';
	return (trim);
}
