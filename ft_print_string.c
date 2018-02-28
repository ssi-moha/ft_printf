/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:08:23 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/12/29 09:34:00 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_arg(char **arg, t_print *option, va_list params)
{
	char *s;

	s = va_arg(params, char*);
	if (option->prc == 0)
		*arg = ft_strdup("");
	else if (!s)
		*arg = ft_strdup("(null)");
	else
		*arg = ft_strdup(s);
}

char		*ft_print_string(va_list params, t_print *option)
{
	char	*ret;
	int		len;
	char	*arg;

	fill_arg(&arg, option, params);
	if (option->width)
		len = option->width;
	else if (option->prc > 0)
		len = option->prc;
	else
		len = ft_strlen(arg);
	ret = ft_memalloc(sizeof(char) * len + 1);
	if (option->prc > 0)
		ret = ft_strncpy(ret, arg, option->prc);
	else
		ret = ft_strcpy(ret, arg);
	if (option->width)
		handle_width(&ret, option);
	return (ret);
}
