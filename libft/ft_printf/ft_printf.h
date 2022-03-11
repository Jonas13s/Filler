/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:06:25 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/09 00:05:40 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <inttypes.h>

# define DIGITS		"0123456789"
# define HEXALOW	"0123456789abcdef"
# define HEXAUPP	"0123456789ABCDEF"
# define OCTAL		"01234567"

typedef struct s_print
{
	va_list		args;
	int			plus;
	int			minus;
	int			zero;
	int			hash;
	int			percent;
	int			null;
	int			space;
	int			dot;
	int			width;
	int			precision;
	int			content_size;
	int			total_length;
}				t_print;

typedef struct s_length
{
	int		h;
	int		l;
	int		lupper;
}			t_length;
/* assign values without unsignedint_value*/
long long	octal_value(t_print *tab, t_length *mod);
long long	hex_value(t_print *tab, t_length *mod);
long long	signedint_value(t_print *tab, t_length *mod);
/*					*/
int			ft_printf(const char *format, ...);
int			ft_convert_args(const char *format, t_print *tab, t_length *mod);
int			add_flags(const char *format, t_print *tab);
int			is_flag(char c);
int			ft_isnumber(char c);
void		init_fstruct(t_length *tab);
void		init_struct(t_print *tab);
int			is_length(char a);
int			print_char(t_print *tab);
int			print_string(t_print *tab);
int			print_percent(void);
int			print_signedint(t_print *tab, t_length *mod);
int			number_count(long long int i);
int			ft_print_char(char c, int i);
char		*hex_conv(unsigned long long i, char *base);
int			print_hex(t_print *tab, char *base, t_length *mod);
int			print_pointer(t_print *tab);
int			print_octal(t_print *tab, t_length *mod);
int			print_unsignedint(t_print *tab, t_length *mod);
int			print_float(t_print *tab, t_length *mod);
char		*ftoa(long double value, t_print *tab);
/* flag set */
int			add_conversion(const char *format, t_print *tab, t_length *mod);
int			add_lengthmod(const char *format, t_length *mod, t_print *tab);
int			add_presicion(const char *format, t_print *tab);
int			add_width(const char *format, t_print *tab);
int			add_flags(const char *format, t_print *tab);
#endif
