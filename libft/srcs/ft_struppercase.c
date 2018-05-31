/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struppercase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:41:46 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/12/10 19:50:12 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_struppercase(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_islower(str[i]))
			str[i] -= 32;
		i++;
	}
	return (str);
}
