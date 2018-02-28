/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_arguns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 05:45:12 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/12/29 19:19:18 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*modif_arguns(va_list params, t_print *option, int base)
{
	char *arg;

	arg = NULL;
	if (!option->mod)
		arg = ft_ulltoa_base(va_arg(params, unsigned int), base);
	else if (!ft_strcmp("hh", option->mod))
		arg = ft_ulltoa_base((unsigned char)va_arg(params, long long), base);
	else if (!ft_strcmp("h", option->mod))
		arg = ft_ulltoa_base((unsigned short)va_arg(params, long long), base);
	else if (!ft_strcmp("l", option->mod))
		arg = ft_ulltoa_base((unsigned long)va_arg(params, long long), base);
	else if (!ft_strcmp("ll", option->mod))
		arg = ft_ulltoa_base((unsigned long long)va_arg(params, long long),
				base);
	else if (!ft_strcmp("j", option->mod))
		arg = ft_ulltoa_base((uintmax_t)va_arg(params, long long), base);
	else if (!ft_strcmp("z", option->mod))
		arg = ft_ulltoa_base((size_t)va_arg(params, long long), base);
	return (arg);
}

char	*modif_argsign(va_list params, t_print *option, int base)
{
	char *arg;

	arg = NULL;
	if (!option->mod)
	{
		arg = ft_lltoa_base((int)va_arg(params, long long), base);
	}
	else if (!ft_strcmp("hh", option->mod))
		arg = ft_lltoa_base((char)va_arg(params, long long), base);
	else if (!ft_strcmp("h", option->mod))
		arg = ft_lltoa_base((short)va_arg(params, long long), base);
	else if (!ft_strcmp("l", option->mod))
		arg = ft_lltoa_base((long)va_arg(params, long long), base);
	else if (!ft_strcmp("ll", option->mod))
		arg = ft_lltoa_base(va_arg(params, long long), base);
	else if (!ft_strcmp("j", option->mod))
		arg = ft_lltoa_base((intmax_t)va_arg(params, long long), base);
	else if (!ft_strcmp("z", option->mod))
		arg = ft_lltoa_base((size_t)va_arg(params, long long), base);
	return (arg);
}
