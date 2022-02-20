/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:49:09 by joivanau          #+#    #+#             */
/*   Updated: 2021/11/12 12:32:54 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	itoa_assist(long int l)
{
	int	count;

	count = 0;
	if (l < 0)
	{
		l = -l;
		count++;
	}
	if (l == 0)
		count++;
	while (l > 0)
	{
		count++;
		l = l / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*str;
	long int		l;
	long int		k;
	int				count;

	l = n;
	k = n;
	count = itoa_assist(l);
	if (k < 0)
		k = -k;
	l = 0;
	str = (char *) malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = '\0';
	count--;
	while (l <= count)
	{
		str[count - l] = k % 10 + '0';
		k = k / 10;
		l++;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
