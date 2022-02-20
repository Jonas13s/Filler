/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:19:02 by joivanau          #+#    #+#             */
/*   Updated: 2021/11/15 16:37:20 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		i;
	size_t		x;

	i = 0;
	if (s2[0] == '\0')
		return ((char *) s1);
	while (s1[i] != '\0' && i <= len)
	{
		x = 0;
		if (s1[i] == s2[x])
		{
			while (s2[x] != '\0' && (i + x) != len)
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
	}
	return (NULL);
}
