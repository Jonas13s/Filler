/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 10:14:39 by joivanau          #+#    #+#             */
/*   Updated: 2022/02/08 03:37:23 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	number_count(long long int i)
{
	int		count;
	char	*s;

	if (i < 0)
		i *= -1;
	s = hex_conv(i, DIGITS);
	count = ft_strlen(s);
	ft_strdel(&s);
	return (count);
}

int	ft_print_char(char c, int i)
{
	while (i > 0)
	{
		ft_putchar(c);
		i--;
	}
	return (0);
}

char	*hex_conv(unsigned long long i, char *base)
{
	char				*string;
	unsigned long long	number;
	size_t				size;
	int					base_len;

	base_len = ft_strlen(base);
	number = i;
	size = 0;
	while (i)
	{
		i /= base_len;
		if (i)
			size++;
	}
	string = ft_strnew(size + 1);
	if (!string)
		return (0);
	while (number > 0)
	{
		string[size--] = base[number % base_len];
		number /= base_len;
	}
	if (size == 0 && string[1] == '\0')
		string[0] = '0';
	return (string);
}

int	ft_convert_args(const char *format, t_print *tab, t_length *mod)
{
	format += add_flags(format, tab);
	format += add_width(format, tab);
	format += add_presicion(format, tab);
	format += add_lengthmod(format, mod, tab);
	format += add_conversion(format, tab, mod);
	return (tab->total_length);
}
