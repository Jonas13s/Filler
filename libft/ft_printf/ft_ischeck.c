/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischeck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:24:47 by joivanau          #+#    #+#             */
/*   Updated: 2022/02/08 03:39:33 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isnumber(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#')
		return (1);
	return (0);
}

int	is_length(char a)
{
	if ((a == 'h') || (a == 'l') || (a == 'L'))
		return (1);
	return (0);
}

void	init_struct(t_print *tab)
{
	tab->plus = 0;
	tab->minus = 0;
	tab->zero = 0;
	tab->hash = 0;
	tab->percent = 0;
	tab->space = 0;
	tab->dot = 0;
	tab->width = 0;
	tab->precision = 0;
	tab->content_size = 0;
	tab->total_length = 0;
	tab->null = 0;
}

void	init_fstruct(t_length *tab)
{
	tab->h = 0;
	tab->l = 0;
	tab->lupper = 0;
}
