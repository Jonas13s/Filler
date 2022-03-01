/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:54:47 by joivanau          #+#    #+#             */
/*   Updated: 2022/02/08 04:24:30 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	content_size(t_print *tab, char *s)
{
	int	len;
	int	k;

	len = ft_strlen(s);
	if (tab->null)
	{
		tab->content_size = len;
		tab->precision = 0;
		return (len);
	}
	k = 2;
	if (tab->precision > len)
		k += tab->precision;
	else
		k += len;
	if (tab->plus || tab->space)
		k++;
	tab->content_size = k;
	return (len);
}

static int	print_start(t_print *tab)
{
	if (tab->null)
		return (0);
	if (tab->plus)
		write(1, "+", 1);
	else if (tab->space)
		write(1, " ", 1);
	write(1, "0x", 2);
	return (0);
}

static int	print_fully(t_print *tab, char *s)
{
	int	len;

	len = content_size(tab, s);
	if (!tab->minus)
		ft_print_char(' ', tab->width - tab->content_size);
	print_start(tab);
	ft_print_char('0', tab->precision - len);
	ft_putstr(s);
	if (tab->minus)
		ft_print_char(' ', tab->width - tab->content_size);
	if (tab->width > tab->content_size)
		tab->content_size = tab->width;
	return (0);
}

int	print_pointer(t_print *tab)
{
	unsigned long long	p;
	char				*s;

	p = va_arg(tab->args, unsigned long long);
	if (p == 0)
	{
		s = ft_strdup("(nil)");
		tab->null = 1;
	}
	else
		s = hex_conv(p, HEXALOW);
	print_fully(tab, s);
	ft_strdel(&s);
	return (tab->content_size);
}
