/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 03:59:46 by joivanau          #+#    #+#             */
/*   Updated: 2022/02/08 04:36:45 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	signedint_value(t_print *tab, t_length *mod)
{
	long long	k;

	if (mod->h == 1)
		k = (short int)va_arg(tab->args, int);
	else if (mod->h == 2)
		k = (signed char)va_arg(tab->args, int);
	else if (mod->l == 1)
		k = (long int)va_arg(tab->args, long);
	else if (mod->l == 2)
		k = (long long int)va_arg(tab->args, long long);
	else
		k = va_arg(tab->args, int);
	return (k);
}

long long	hex_value(t_print *tab, t_length *mod)
{
	long long	k;

	if (mod->h == 1)
		k = (unsigned short int)va_arg(tab->args, unsigned int);
	else if (mod->h == 2)
		k = (unsigned char)va_arg(tab->args, unsigned int);
	else if (mod->l == 1)
		k = (unsigned long int)va_arg(tab->args, unsigned long);
	else if (mod->l == 2)
		k = (unsigned long long int)va_arg(tab->args, unsigned long long);
	else
		k = va_arg(tab->args, unsigned int);
	return (k);
}

long long	octal_value(t_print *tab, t_length *mod)
{
	long long	k;

	if (mod->h == 1)
		k = (unsigned short int)va_arg(tab->args, int);
	else if (mod->h == 2)
		k = (unsigned char)va_arg(tab->args, int);
	else if (mod->l == 1)
		k = (unsigned long int)va_arg(tab->args, long);
	else if (mod->l == 2)
		k = (unsigned long long int)va_arg(tab->args, long long);
	else
		k = va_arg(tab->args, unsigned int);
	return (k);
}
