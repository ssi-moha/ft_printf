/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:31:31 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/12/29 11:18:47 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	make_prc(char *arg, int prc, char **ret)
{
	int		i;
	char	*add;
	int		size;

	i = 0;
	size = prc - ft_strlen(arg);
	add = ft_strnew(size);
	add = ft_memset(add, '0', size);
	*ret = ft_strjoin(*ret, add);
}

static void	make_zero(char *arg, t_print *option, char **ret)
{
	char	*add;
	int		size;

	size = option->width - ft_strlen(arg);
	if (*ret[0] == '0')
		size -= 2;
	if (*arg == '-')
		arg++;
	add = ft_strnew(size);
	add = ft_memset(add, '0', size);
	*ret = ft_strjoin(*ret, add);
	option->width = 0;
}

static void	make_width(char *arg, t_print *option, char **ret)
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

char		*ft_print_hex(va_list params, t_print *option)
{
	char *ret;
	char *arg;

	arg = modif_arguns(params, option, 16);
	ret = malloc(1);
	ret = ft_strdup("\0");
	option->prc == 0 && ft_strcmp(arg, "0") == 0 ? ret = ft_strdup("") : ret;
	if (option->sharp == 1 && ft_strcmp(arg, "0") != 0)
		ret = ft_strdup("0x");
	if (option->prc > -1)
	{
		if (option->prc > (int)ft_strlen(arg))
			make_prc(arg, option->prc, &ret);
		option->zero = 0;
	}
	if (option->zero && option->width > option->prc
			&& option->width > ft_strlen(arg) && !option->minus)
		make_zero(arg, option, &ret);
	if (!(option->prc == 0 && ft_strcmp(arg, "0") == 0))
		ret = ft_strjoin(ret, arg);
	if (option->width > option->prc && option->width > ft_strlen(arg))
		make_width(arg, option, &ret);
	if (option->type == 11)
		ret = ft_struppercase(ret);
	return (ret);
}
