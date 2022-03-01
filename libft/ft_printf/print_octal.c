/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:10:56 by joivanau          #+#    #+#             */
/*   Updated: 2022/02/08 04:31:21 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	content_size(t_print *tab, char *s)
{
	int	len;
	int	k;

	len = ft_strlen(s);
	if (tab->precision > len)
		k = tab->precision;
	else
		k = len;
	if (tab->hash && tab->precision <= len && !tab->null)
	{
		tab->precision = len + 1;
		k++;
	}
	tab->content_size = k;
	return (len);
}

static int	print_fully(t_print *tab, char *s)
{
	int	len;

	len = content_size(tab, s);
	if (tab->zero && !tab->dot && !tab->minus)
	{
		ft_print_char('0', tab->precision - len);
		ft_print_char('0', tab->width - tab->content_size);
		ft_putstr(s);
	}
	else
	{
		if (!tab->minus)
			ft_print_char(' ', tab->width - tab->content_size);
		ft_print_char('0', tab->precision - len);
		ft_putstr(s);
		if (tab->minus)
			ft_print_char(' ', tab->width - tab->content_size);
	}
	if (tab->width > tab->content_size)
		tab->content_size = tab->width;
	return (0);
}

int	print_octal(t_print *tab, t_length *mod)
{
	char				*s;
	unsigned long long	k;

	k = octal_value(tab, mod);
	if (k == 0)
	{
		if (tab->dot && !tab->precision)
			s = ft_strdup("");
		else
		{
			s = ft_strdup("0");
			tab->null = 1;
		}
	}
	else
		s = hex_conv(k, OCTAL);
	print_fully(tab, s);
	ft_strdel(&s);
	return (tab->content_size);
}
