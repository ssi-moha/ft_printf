/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:13:25 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/12/29 18:23:40 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		fill_sign(char **ret, t_print *option, char *arg)
{
	if (arg[0] == '-')
	{
		*ret[0] = '-';
	}
	else if (option->plus)
		*ret[0] = '+';
	else if (option->space)
		*ret[0] = ' ';
}

static void		make_prc(char *arg, int prc, char **ret)
{
	char	*add;
	int		size;

	size = prc - ft_strlen(arg);
	if (*arg == '-')
	{
		size++;
		arg++;
	}
	add = ft_strnew(size);
	add = ft_memset(add, '0', size);
	*ret = ft_strcat(*ret, add);
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

char			*ft_print_int(va_list params, t_print *option)
{
	char	*ret;
	char	*arg;
	int		len;

	if (option->type == 4)
		option->mod = ft_strdup("l");
	arg = modif_argsign(params, option, 10);
	len = set_len(arg, option);
	ret = ft_strnew(len);
	ft_atoi(arg) == 0 && !option->prc ? ret = ft_strdup("") : ret;
	fill_sign(&ret, option, arg);
	if (option->prc > -1)
	{
		if (option->prc >= (int)ft_strlen(arg))
			make_prc(arg, option->prc, &ret);
		option->zero = 0;
	}
	if (option->zero && option->width > option->prc
			&& option->width > ft_strlen(arg) && !option->minus)
		make_zero(arg, option, &ret);
	arg[0] == '-' ? arg++ : arg;
	!(ft_atoi(arg) == 0 && !option->prc) ? ret = ft_strcat(ret, arg) : ret;
	if (option->width > option->prc && option->width > ft_strlen(arg))
		make_width(arg, option, &ret);
	return (ret);
}
