/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:28:41 by joivanau          #+#    #+#             */
/*   Updated: 2022/02/08 04:51:51 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_width(t_print *tab)
{
	char	*s;
	char	c;

	c = (char) va_arg(tab->args, int);
	if (tab->width > 0)
	{
		tab->width--;
		s = ft_strnew(tab->width);
		s = ft_memset(s, ' ', tab->width);
	}
	else
		s = ft_strnew(tab->width);
	if (tab->minus == 1)
	{
		write(1, &c, 1);
		ft_putstr(s);
	}
	else
	{
		ft_putstr(s);
		write(1, &c, 1);
	}
	free(s);
}

int	print_char(t_print *tab)
{
	print_width(tab);
	return (tab->width + 1);
}
