/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_signedinteger.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:23:41 by joivanau          #+#    #+#             */
/*   Updated: 2022/02/08 04:38:22 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_sign(t_print *tab, long long i)
{
	if (i < 0)
		ft_putchar('-');
	else if (tab->plus)
		ft_putchar('+');
	else if (tab->space)
		ft_putchar(' ');
	return (0);
}

static int	print_digits(t_print *tab, long long i)
{
	char	*s;

	if (i < 0)
		i *= -1;
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

static int	initialize_len(t_print *tab, long long i)
{
	int	k;

	if (tab->precision > number_count(i))
		k = tab->precision;
	else
		k = number_count(i);
	if (i < 0 || tab->space || tab->plus)
		k++;
	if (tab->dot == 1 && tab->precision == 0 && i == 0)
		k = 0;
	return (k);
}

static int	print_fully(t_print *tab, long long i)
{
	int	len;

	len = initialize_len(tab, i);
	if (!tab->minus && !tab->zero)
		ft_print_char(' ', tab->width - len);
	print_sign(tab, i);
	if (tab->zero && !tab->minus)
		ft_print_char('0', tab->width - len);
	ft_print_char('0', tab->precision - number_count(i));
	print_digits(tab, i);
	if (tab->minus)
		ft_print_char(' ', tab->width - len);
	return (len);
}

int	print_signedint(t_print *tab, t_length *mod)
{
	unsigned long long	i;
	int					count;

	i = signedint_value(tab, mod);
	if ((tab->dot && tab->zero) || (tab->zero && tab->minus))
		tab->zero = 0;
	count = print_fully(tab, i);
	if (tab->width > count)
		count = tab->width;
	return (count);
}
