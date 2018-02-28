/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 18:21:21 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/12/29 09:21:48 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_option(t_print *option)
{
	if (option->mod)
		free(option->mod);
	if (option)
		free(option);
	option = NULL;
}
