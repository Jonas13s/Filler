/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:53:12 by joivanau          #+#    #+#             */
/*   Updated: 2022/02/08 04:00:26 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printing_hex(char *s, t_print *tab)
{
	if (tab->dot == 1 && tab->precision == 0 && tab->null)
		return (0);
	ft_putstr(s);
	return (0);
}

static int	print_start(t_print *tab, int mode)
{
	if (tab->hash && mode == 1 && tab->null == 0)
		ft_putstr("0x");
	if (tab->hash && mode == 0 && tab->null == 0)
		ft_putstr("0X");
	return (0);
}

static int	int_content_size(t_print *tab, char *s)
{
	int	k;
	int	length;

	length = ft_strlen(s);
	k = 0;
	if (tab->precision > length)
		k = tab->precision;
	else
		k = length;
	if (tab->hash && tab->null == 0)
		k += 2;
	if (tab->dot == 1 && tab->precision == 0 && tab->null)
		k = 0;
	tab->content_size = k;
	return (length);
}

static int	print_right_allign(t_print *tab, char *s, int mode)
{
	int	length;

	length = int_content_size(tab, s);
	if (tab->zero && tab->minus == 0)
	{
		print_start(tab, mode);
		ft_print_char('0', tab->precision - length);
		ft_print_char('0', tab->width - tab->content_size);
		printing_hex(s, tab);
	}
	else
	{
		if (!tab->minus)
			ft_print_char(' ', tab->width - tab->content_size);
		print_start(tab, mode);
		ft_print_char('0', tab->precision - length);
		printing_hex(s, tab);
		if (tab->minus)
			ft_print_char(' ', tab->width - tab->content_size);
	}
	if (tab->width > tab->content_size)
		tab->content_size = tab->width;
	return (tab->content_size);
}

int	print_hex(t_print *tab, char *base, t_length *mod)
{
	int				count;
	long long		k;
	char			*string;
	int				mode;

	if (ft_strcmp(base, "0123456789ABCDEF") == 0)
		mode = 0;
	else
		mode = 1;
	k = hex_value(tab, mod);
	if ((tab->dot && tab->zero) || (tab->zero && tab->minus))
		tab->zero = 0;
	if (k != 0)
		string = hex_conv(k, base);
	else
	{
		tab->null = 1;
		string = ft_strdup("0");
	}
	count = print_right_allign(tab, string, mode);
	ft_strdel(&string);
	return (count);
}
