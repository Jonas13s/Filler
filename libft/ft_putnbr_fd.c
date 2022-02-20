/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:24:40 by joivanau          #+#    #+#             */
/*   Updated: 2021/11/11 14:30:48 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	k;

	k = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n == -2147483648)
		{
			n++;
			k = 1;
		}
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		if (k == 1)
			ft_putchar_fd(n % 10 + '1', fd);
		else
			ft_putchar_fd(n % 10 + '0', fd);
	}
	if (n < 10)
		ft_putchar_fd(n % 10 + '0', fd);
}
