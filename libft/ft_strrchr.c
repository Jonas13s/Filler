/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:07:30 by joivanau          #+#    #+#             */
/*   Updated: 2021/12/03 03:31:33 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	k;

	k = ft_strlen(s);
	while (k > 0)
	{
		if (s[k] == c)
			break ;
		k--;
	}
	if (s[k] == c)
		return ((char *) &s[k]);
	return (NULL);
}
