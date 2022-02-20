/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:58:48 by joivanau          #+#    #+#             */
/*   Updated: 2021/11/08 12:55:26 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int	k;

	k = 0;
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			n++;
			k = 1;
		}
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		if (k == 1)
			ft_putchar(n % 10 + '1');
		else
			ft_putchar(n % 10 + '0');
	}
	if (n < 10)
	{
		ft_putchar(n % 10 + '0');
	}
}
