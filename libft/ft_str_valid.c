/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_valid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 01:30:38 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/03 01:30:48 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_valid(char *str, char *symbols)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(symbols, str[i]))
			return (0);
		i++;
	}
	return (1);
}
