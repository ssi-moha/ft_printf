/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:36:09 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/12/29 17:28:23 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_type(char c)
{
	char	*type;
	int		i;

	i = 0;
	type = ft_strdup("sSpdDioOuUxXcC%");
	while (type[i])
	{
		if (type[i] == c)
		{
			free(type);
			return (i);
		}
		i++;
	}
	free(type);
	return (-1);
}
