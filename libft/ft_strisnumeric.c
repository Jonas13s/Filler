/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnumeric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:22:15 by joivanau          #+#    #+#             */
/*   Updated: 2021/11/12 18:27:41 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisnumeric(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]) == 1)
			i++;
		else
			break ;
	}
	if (s[i] == '\0')
		return (1);
	return (0);
}
