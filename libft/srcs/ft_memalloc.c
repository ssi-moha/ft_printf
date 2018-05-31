/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 06:18:30 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/11/11 14:54:40 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char *mem;

	if ((mem = malloc(sizeof(void*) * size)) == 0)
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}
