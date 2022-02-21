/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:36:29 by joivanau          #+#    #+#             */
/*   Updated: 2022/02/21 03:36:56 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_free2d(char **str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	//free(str);
}

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
