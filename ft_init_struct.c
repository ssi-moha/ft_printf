/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:19:11 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/12/29 17:06:06 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print		*ft_init_struct(void)
{
	t_print *start;

	if (!(start = (t_print *)malloc(sizeof(t_print))))
		return (NULL);
	start->type = -1;
	start->zero = 0;
	start->plus = 0;
	start->minus = 0;
	start->sharp = 0;
	start->space = 0;
	start->width = 0;
	start->prc = -1;
	start->conv = 0;
	start->count = 0;
	start->len = 0;
	start->mod = NULL;
	return (start);
}
