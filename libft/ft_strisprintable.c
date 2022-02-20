/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisprintable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:29:41 by joivanau          #+#    #+#             */
/*   Updated: 2021/11/12 18:29:45 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisprintable(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_isprint(s[i]) == 1)
			i++;
		else
			break ;
	}
	if (s[i] == '\0')
		return (1);
	return (0);
}
