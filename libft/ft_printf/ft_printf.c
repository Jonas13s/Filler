/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 19:01:49 by joivanau          #+#    #+#             */
/*   Updated: 2022/02/20 04:53:35 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf2(const char *format, t_print *tab, t_length *mod)
{
	ssize_t	len;

	len = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			init_struct(tab);
			init_fstruct(mod);
			++format;
			if (*format == '\0')
			{
				len = -1;
				break ;
			}
			format += ft_convert_args(format, tab, mod);
			len += tab->content_size;
		}
		else if (*format != '%')
		{
			len += write(1, format, 1);
			++format;
		}
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	t_print		*tab;
	t_length	*mod;
	size_t		length;

	tab = (t_print *) malloc(sizeof(t_print));
	mod = (t_length *) malloc(sizeof(t_length));
	if (!mod || !tab)
		return (-1);
	init_struct(tab);
	va_start(tab->args, format);
	length = ft_printf2(format, tab, mod);
	va_end(tab->args);
	free (tab);
	free (mod);
	return (length);
}
