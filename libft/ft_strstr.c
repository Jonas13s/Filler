/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:51:16 by joivanau          #+#    #+#             */
/*   Updated: 2021/11/08 12:54:46 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	if (s2[0] == '\0')
		return ((char *) s1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[x])
		{
			while (s2[x] != '\0')
			{
				if (s1[i + x] == s2[x])
					x++;
				else
					break ;
				if (s2[x] == '\0')
					return ((char *) &s1[i]);
			}
		}
		i++;
		x = 0;
	}
	return (NULL);
}
