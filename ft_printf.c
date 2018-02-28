/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:28:54 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/02/14 16:36:28 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_clean(char *new, int *i, const char *s, va_list params)
{
	t_print *option;
	int		l;

	option = ft_init_struct();
	new = ft_parse(option, params, s + *i);
	write(1, new, option->len);
	*i += option->count + 1;
	l = option->len;
	free_option(option);
	if (new)
		ft_strdel(&new);
	return (l);
}

void			ft_count(const char *s, va_list params, int *k)
{
	int		i;
	char	*new;
	char	*buff;
	int		z;

	i = 0;
	new = NULL;
	z = 0;
	while (s[i])
	{
		if (!(buff = ft_strnew(ft_strclen(s + i, '%'))))
			return ;
		while (s[i] != '%' && s[i])
		{
			buff[z++] = s[i++];
			(*k)++;
		}
		write(1, buff, z);
		if (buff)
			ft_strdel(&buff);
		z = 0;
		if (s[i] == '%')
			*k += ft_clean(new, &i, s, params);
	}
}

int				ft_printf(const char *s, ...)
{
	va_list params;
	int		k;

	k = 0;
	va_start(params, s);
	ft_count(s, params, &k);
	va_end(params);
	return (k);
}
