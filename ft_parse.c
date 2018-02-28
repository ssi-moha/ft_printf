/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 13:43:51 by ssi-moha          #+#    #+#             */
/*   Updated: 2018/02/14 16:37:41 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isflag(char c)
{
	char	*flag;
	int		i;

	i = 0;
	flag = ft_strdup("0-+# ");
	while (flag[i])
	{
		if (flag[i] == c)
		{
			free(flag);
			return (1);
		}
		i++;
	}
	free(flag);
	return (0);
}

void	get_flag(t_print *option, const char *s, int *i)
{
	(*i)++;
	while (ft_isflag(s[*i]) && s[*i])
	{
		if (s[*i] == '0')
			option->zero = 1;
		else if (s[*i] == '-')
			option->minus = 1;
		else if (s[*i] == '+')
			option->plus = 1;
		else if (s[*i] == '#')
			option->sharp = 1;
		else if (s[*i] == ' ')
			option->space = 1;
		(*i)++;
	}
}

void	get_prc(t_print *option, const char *s, int *i)
{
	option->width = ft_atoi(s + *i);
	while (ft_isdigit(s[*i]) && s[*i])
		(*i)++;
	if (s[*i] == '.')
		option->prc = ft_atoi(s + *i + 1);
}

void	get_type(t_print *option, const char *s, int *i)
{
	while (find_type(s[*i]) < 0 && s[*i])
		(*i)++;
	if (find_type(s[*i]) >= 0)
		option->type = find_type(s[*i]);
}

char	*ft_parse(t_print *option, va_list params, const char *s)
{
	int		i;
	char	*ret;

	i = 0;
	get_flag(option, s, &i);
	get_prc(option, s, &i);
	get_modif(option, s, &i);
	get_type(option, s, &i);
	option->count = i;
	ret = type_ret(option, params);
	if (option->type != 12)
		option->len = ft_strlen(ret);
	return (ret);
}
