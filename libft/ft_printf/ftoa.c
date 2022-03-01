/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:25:58 by joivanau          #+#    #+#             */
/*   Updated: 2022/02/08 01:54:59 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	banker_round(long double value, t_print *tab)
{
	long double	round;
	int			i;

	i = 0;
	round = 0.5;
	while (i < tab->precision)
	{
		round /= 10;
		i++;
	}
	if (((intmax_t) value + 1) < (value + round))
		return (value + round);
	if (((intmax_t) value + 1) % 2 != 0 && tab->precision == 0)
		return (value);
	return (value + round);
}

static char	*ft_round(long double fraction, int start, char *str, t_print *tab)
{
	int	i;

	i = 0;
	while (i < tab->precision)
	{
		fraction *= 10;
		str[i + start] = (intmax_t)fraction + '0';
		fraction -= (intmax_t)fraction;
		i++;
	}
	return (str);
}

char	*ftoa(long double value, t_print *tab)
{
	char		*string;
	char		*temp;
	intmax_t	integer;
	long double	fraction;
	int			i;

	if (value < 0)
		value *= -1;
	value = banker_round(value, tab);
	integer = (intmax_t) value;
	temp = ft_itoa(integer);
	fraction = value - (long double)integer;
	string = ft_strnew(ft_strlen(temp) + tab->precision + 2);
	if (!string)
		return (NULL);
	string = ft_strcpy(string, temp);
	ft_strdel(&temp);
	if (tab->precision > 0 || tab->hash == 1)
	{
		i = ft_strlen(string);
		string[i] = '.';
		i++;
		return (ft_round(fraction, i, string, tab));
	}
	return (string);
}
