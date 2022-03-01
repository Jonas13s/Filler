/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:46:49 by joivanau          #+#    #+#             */
/*   Updated: 2022/02/08 03:39:45 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	add_flags(const char *format, t_print *tab)
{
	size_t	i;

	i = 0;
	while (is_flag(format[i]))
	{
		if (format[i] == ' ')
			tab->space = 1;
		if (format[i] == '#')
			tab->hash = 1;
		if (format[i] == '0')
			tab->zero = 1;
		if (format[i] == '-')
		{
			tab->minus = 1;
			tab->zero = 0;
		}
		if (format[i] == '+')
		{
			tab->plus = 1;
			tab->space = 0;
		}
		i++;
	}
	tab->total_length += i;
	return (i);
}

int	add_width(const char *format, t_print *tab)
{
	size_t	i;

	i = 0;
	if (format[i] == '*')
	{
		tab->width = va_arg(tab->args, int);
		if (tab->width < 0)
		{
			tab->width *= -1;
			tab->minus = 1;
		}
		i = 1;
		tab->total_length += i;
		return (i);
	}
	while (ft_isnumber(format[i]))
		tab->width = (tab->width * 10) + (format[i++] - '0');
	tab->total_length += i;
	return (i);
}

int	add_presicion(const char *format, t_print *tab)
{
	size_t	i;

	i = 0;
	if (format[i] == '.')
	{
		i++;
		tab->dot = 1;
		if (format[i] == '*')
		{
			tab->precision = va_arg(tab->args, int);
			if (tab->precision < 0)
			{
				tab->precision = 0;
				tab->dot = 0;
			}
			i++;
			tab->total_length += i;
			return (i);
		}
		while (ft_isnumber(format[i]))
			tab->precision = (tab->precision * 10) + (format[i++] - '0');
	}
	tab->total_length += i;
	return (i);
}

int	add_lengthmod(const char *format, t_length *mod, t_print *tab)
{
	size_t	i;

	i = 0;
	while (is_length(format[i]))
	{
		if (format[i] == 'h')
			mod->h++;
		if (format[i] == 'l')
			mod->l++;
		if (format[i] == 'L')
			mod->lupper++;
		i++;
	}
	tab->total_length += i;
	return (i);
}

int	add_conversion(const char *format, t_print *tab, t_length *mod)
{
	if (*format == 'c')
		tab->content_size = print_char(tab);
	else if (*format == 's')
		tab->content_size = print_string(tab);
	else if (*format == '%')
		tab->content_size = print_percent();
	else if (*format == 'd')
		tab->content_size = print_signedint(tab, mod);
	else if (*format == 'i')
		tab->content_size = print_signedint(tab, mod);
	else if (*format == 'x')
		tab->content_size = print_hex(tab, HEXALOW, mod);
	else if (*format == 'X')
		tab->content_size = print_hex(tab, HEXAUPP, mod);
	else if (*format == 'p')
		tab->content_size = print_pointer(tab);
	else if (*format == 'o')
		tab->content_size = print_octal(tab, mod);
	else if (*format == 'u')
		tab->content_size = print_unsignedint(tab, mod);
	else if (*format == 'f')
		tab->content_size = print_float(tab, mod);
	if (*format != '\0')
		tab->total_length++;
	return (1);
}
