/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:49:05 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/12/29 17:12:20 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		det_len(char *arg, t_print *option)
{
	int i;
	int arglen;

	i = 0;
	arglen = ft_strlen(arg);
	if (option->prc >= option->width && option->prc > arglen)
		i = option->prc;
	else if (option->width && option->width > arglen)
		i = option->width;
	else
	{
		i = arglen;
		option->width = 0;
	}
	if (option->space || option->plus || option->sharp)
		i++;
	return (i);
}

static void		make_zero(char *arg, t_print *option, char **ret)
{
	char	*add;
	int		size;

	size = option->width - ft_strlen(arg);
	if (arg[0] != '-')
		size -= ft_strlen(*ret);
	if (*arg == '-')
		arg++;
	add = ft_strnew(size);
	add = ft_memset(add, '0', size);
	*ret = ft_strcat(*ret, add);
	option->width = 0;
}

static void		make_prc(char *arg, int prc, char **ret)
{
	char	*add;
	int		size;

	size = prc - ft_strlen(arg);
	add = ft_strnew(size);
	add = ft_memset(add, '0', size);
	*ret = ft_strcat(*ret, add);
}

static void		make_width(char *arg, t_print *option, char **ret)
{
	int		size;
	char	*add;

	size = option->width - ft_strlen(*ret);
	add = ft_strnew(size + 1);
	add = ft_memset(add, ' ', size);
	if (option->minus)
		*ret = ft_strjoin(*ret, add);
	else
		*ret = ft_strjoin(add, *ret);
}

char			*ft_print_uns(va_list params, t_print *option)
{
	char	*ret;
	char	*arg;

	if (option->type == 9)
		arg = ft_ulltoa((unsigned long long)va_arg(params, long long));
	else
		arg = modif_arguns(params, option, 10);
	ret = ft_strnew(det_len(arg, option) + 1);
	if (option->prc > -1)
	{
		if (option->prc > (int)ft_strlen(arg))
			make_prc(arg, option->prc, &ret);
		option->zero = 0;
	}
	if (option->zero && option->width > option->prc &&
			option->width > ft_strlen(arg))
		make_zero(arg, option, &ret);
	if (ft_atoi(arg) == 0 && !option->prc)
		return (ret);
	ret = ft_strcat(ret, arg);
	if (option->width > option->prc && option->width > ft_strlen(arg))
		make_width(arg, option, &ret);
	return (ret);
}
