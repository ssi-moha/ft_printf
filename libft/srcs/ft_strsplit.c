/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:58:02 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/03/03 11:01:25 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_cwords(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (s[i])
	{
		if (s[i] != c)
			if (s[i + 1] == c || s[i + 1] == '\0')
				j++;
		i++;
	}
	return (j);
}

static int		ft_cletter(const char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (s[i] && s[i] != c)
	{
		i++;
		j++;
	}
	return (j);
}

static char		*ft_stradup(const char *s, int c, int i)
{
	char	*dest;
	int		j;

	j = 0;
	dest = malloc(sizeof(char*) * ft_cletter(s, c) + 1);
	if (dest == NULL)
		return (NULL);
	while (s[i] && s[i] != c)
	{
		dest[j] = s[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (!(tab = malloc(sizeof(char**) * ft_cwords(s, c) + 1)))
		return (NULL);
	while (s[j])
	{
		if (s[j] != c)
		{
			tab[i] = ft_stradup(s, c, j);
			i++;
			while (s[j] != c && s[j])
				j++;
		}
		if (s[j] != '\0')
			j++;
	}
	tab[i] = 0;
	return (tab);
}
