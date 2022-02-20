/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:34:54 by joivanau          #+#    #+#             */
/*   Updated: 2021/11/12 18:35:23 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisalpha(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isalpha(s[i]) == 1)
			i++;
		else
			break ;
	}
	if (s[i] == '\0')
		return (1);
	return (0);
}
