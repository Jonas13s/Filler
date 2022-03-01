/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsignedint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:19:30 by joivanau          #+#    #+#             */
/*   Updated: 2022/02/08 04:41:59 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	unsigned_count(unsigned long long i)
{
	char	*s;
	ssize_t	count;

	s = hex_conv(i, DIGITS);
	count = ft_strlen(s);
	ft_strdel(&s);
	return (count);
}

static unsigned long long	unsignedint_value(t_print *tab, t_length *mod)
{
	long long	k;

	if (mod->h == 1)
		k = (unsigned short int)va_arg(tab->args, unsigned int);
	else if (mod->h == 2)
		k = (unsigned char)va_arg(tab->args, unsigned int);
	else if (mod->l == 1)
		k = (unsigned long int)va_arg(tab->args, unsigned long);
	else if (mod->l == 2)
		k = (unsigned long long int)va_arg(tab->args, unsigned long long);
	else
		k = va_arg(tab->args, unsigned int);
	return (k);
}

static int	print_digits(t_print *tab, unsigned long long i)
{
	char	*s;

	if (tab->dot == 1 && tab->precision == 0 && i == 0)
		return (0);
	else
	{
		s = hex_conv(i, DIGITS);
		ft_putstr(s);
		ft_strdel(&s);
	}
	return (0);
}

static int	print_fully(t_print *tab, long long i)
{
	int	len;

	if (tab->precision > unsigned_count(i))
		len = tab->precision;
	else
		len = unsigned_count(i);
	if (tab->dot == 1 && tab->precision == 0 && i == 0)
		len = 0;
	if (!tab->minus && !tab->zero)
		ft_print_char(' ', tab->width - len);
	if (tab->zero && !tab->minus)
		ft_print_char('0', tab->width - len);
	ft_print_char('0', tab->precision - unsigned_count(i));
	print_digits(tab, i);
	if (tab->minus)
		ft_print_char(' ', tab->width - len);
	return (len);
}

int	print_unsignedint(t_print *tab, t_length *mod)
{
	unsigned long long	i;
	int					count;

	i = unsignedint_value(tab, mod);
	if ((tab->dot && tab->zero) || (tab->zero && tab->minus))
		tab->zero = 0;
	count = print_fully(tab, i);
	if (tab->width > count)
		count = tab->width;
	return (count);
}
