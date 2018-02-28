/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_modif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 09:41:42 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/12/29 17:08:45 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_mod(char c)
{
	if (c == 'l' || c == 'h' || c == 'z' || c == 'j')
		return (1);
	return (0);
}

void	get_modif(t_print *option, const char *s, int *i)
{
	while ((!(find_mod(s[*i])) && find_type(s[*i]) < 0 && s[*i]))
		(*i)++;
	if (ft_strncmp(&s[*i], "j", 1) == 0)
		option->mod = ft_strdup("j");
	else if (ft_strncmp(&s[*i], "z", 1) == 0)
		option->mod = ft_strdup("z");
	else if (ft_strncmp(&s[*i], "hh", 2) == 0)
		option->mod = ft_strdup("hh");
	else if (ft_strncmp(&s[*i], "ll", 2) == 0)
		option->mod = ft_strdup("ll");
	else if (ft_strncmp(&s[*i], "h", 1) == 0)
		option->mod = ft_strdup("h");
	else if (ft_strncmp(&s[*i], "l", 1) == 0)
		option->mod = ft_strdup("l");
}
