/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:18:53 by joivanau          #+#    #+#             */
/*   Updated: 2021/11/08 16:18:18 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	signcheck(int *s, const char *str)
{
	int	k;
	int	end;

	end = 1;
	k = 0;
	while (ft_isspace(str[k]) != 0)
		k++;
	if (str[k] == '+' || str[k] == '-')
	{
		if (str[k] == '-')
			end = -1;
		k++;
	}
	*s = end;
	return (k);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	start;
	int				end;

	start = 0;
	i = signcheck(&end, str);
	while (str[i] != '\0')
	{
		if (start > 2147483647)
		{
			if (end == 1)
				return (-1);
			else
				return (0);
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			start = start * 10 + str[i] - 48;
			i++;
		}
		else
			return (start * end);
	}
	return (start * end);
}
