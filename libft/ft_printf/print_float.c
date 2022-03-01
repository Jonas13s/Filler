/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:00:24 by joivanau          #+#    #+#             */
/*   Updated: 2022/02/08 03:49:32 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_sign(long double number, t_print *tab)
{
	if (tab->plus && (1 / number >= 0))
		ft_putchar('+');
	else if (tab->space && (1 / number >= 0))
		ft_putchar(' ');
}

static int	ft_isinf(long double x)
{
	if (x == -1.0 / 0.0)
		return (-1);
	if (x == 1.0 / 0.0)
		return (1);
	return (0);
}

static int	print_count(long double number, char *string, t_print *tab)
{
	int	count;

	count = ft_strlen(string);
	if (number < 0 || (1 / number < 0))
		count++;
	if ((tab->space && 1 / number >= 0) || (tab->plus && 1 / number >= 0))
		count++;
	return (count);
}

static int	print_right_allign(long double number, char *string, t_print *tab)
{
	int	count;

	count = print_count(number, string, tab);
	if (tab->zero && tab->minus == 0)
	{
		if (number < 0 || 1 / number < 0)
			ft_putchar('-');
		print_sign(number, tab);
		ft_print_char('0', tab->width - count);
		ft_putstr(string);
	}
	else
	{
		if (!tab->minus)
			ft_print_char(' ', tab->width - count);
		if (number < 0 || 1 / number < 0)
			ft_putchar('-');
		print_sign(number, tab);
		ft_putstr(string);
		if (tab->minus)
			ft_print_char(' ', tab->width - count);
	}
	if (tab->width > count)
		count = tab->width;
	return (count);
}

int	print_float(t_print *tab, t_length *mod)
{
	long double	number;
	char		*string;
	int			count;

	if (mod->lupper == 1)
		number = va_arg(tab->args, long double);
	else
		number = va_arg(tab->args, double);
	if (tab->dot == 0)
	{
		tab->dot = 1;
		tab->precision = 6;
	}
	if (ft_isinf(number) == 1 || ft_isinf(number) == -1)
		string = ft_strdup("inf");
	else if (number != number)
		string = ft_strdup("-nan");
	else
		string = ftoa(number, tab);
	count = print_right_allign(number, string, tab);
	ft_strdel(&string);
	return (count);
}
