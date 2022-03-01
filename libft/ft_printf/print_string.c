/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:40:49 by joivanau          #+#    #+#             */
/*   Updated: 2022/02/08 04:50:03 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*format_presicion(t_print *tab, char *text)
{
	int		k;
	char	*temp;

	if (tab->dot == 1)
	{
		if (tab->precision == 0 || (tab->null == 1 && tab->precision < 6))
		{
			ft_strdel(&text);
			text = ft_strdup("");
			return (text);
		}
		k = tab->precision;
		if ((size_t)tab->precision > ft_strlen(text))
			k = ft_strlen(text);
		temp = ft_strsub(text, 0, k);
		ft_strdel(&text);
		text = ft_strdup(temp);
		ft_strdel(&temp);
	}
	return (text);
}

static char	*assign_str(t_print *tab)
{
	char	*temp;
	char	*str;

	temp = va_arg(tab->args, char *);
	if (temp == NULL)
	{
		str = ft_strdup("(null)");
		tab->null = 1;
	}
	else
		str = ft_strdup(temp);
	return (str);
}

static char	*format_string(t_print *tab)
{
	char	*s;
	char	*str;
	char	*string;

	str = assign_str(tab);
	str = format_presicion(tab, str);
	tab->width = tab->width - ft_strlen(str);
	if (tab->width > 0)
	{
		s = ft_strnew(tab->width);
		ft_memset(s, ' ', tab->width);
	}
	else
		return (str);
	if (tab->minus == 1 && tab->width > 0)
		string = ft_strjoin(str, s);
	if (tab->minus == 0 && tab->width > 0)
		string = ft_strjoin(s, str);
	ft_strdel(&str);
	ft_strdel(&s);
	return (string);
}

int	print_string(t_print *tab)
{
	char	*s;
	int		i;

	s = format_string(tab);
	ft_putstr(s);
	i = ft_strlen(s);
	ft_strdel(&s);
	return (i);
}
