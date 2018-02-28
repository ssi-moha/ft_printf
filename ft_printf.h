/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssi-moha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 13:29:22 by ssi-moha          #+#    #+#             */
/*   Updated: 2017/12/29 19:04:01 by ssi-moha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/includes/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int					ft_printf(const char *s, ...);
typedef struct		s_print
{
	int				type;
	int				zero;
	int				plus;
	int				minus;
	int				sharp;
	int				space;
	int				width;
	int				prc;
	int				conv;
	char			*mod;
	int				count;
	int				len;
}					t_print;
char				*ft_parse(t_print *option, va_list params, const char *s);
int					find_type(char c);
void				get_modif(t_print *option, const char *s, int *i);
t_print				*ft_init_struct(void);
char				*ft_print_string(va_list params, t_print *option);
char				*ft_print_int(va_list params, t_print *option);
char				*ft_print_grandint(va_list params, t_print *option);
char				*ft_print_oct(va_list params, t_print *option);
char				*ft_print_uns(va_list params, t_print *option);
char				*ft_print_hex(va_list params, t_print *option);
char				*ft_print_char(va_list params, t_print *option);
char				*ft_print_pointer(va_list params, t_print *option);
char				*type_ret(t_print *option, va_list params);
void				handle_width(char **ret, t_print *option);
char				*ft_lltoa(long long n);
char				*ft_ulltoa(unsigned long long n);
char				*ft_lltoa_base(long long n, int base);
char				*ft_ulltoa_base(unsigned long long n, int base);
char				*modif_arguns(va_list params, t_print *option, int base);
char				*modif_argsign(va_list params, t_print *option, int base);
int					ft_define_len(char *arg, t_print *option);
char				*handle_sign(char *arg, char *ret, t_print *option);
char				*ft_handle_prcu(char *arg, int len, int i);
char				*handle_prc(char *arg, int len, int i);
void				free_option(t_print *option);
int					set_len(char *arg, t_print *option);
#endif
