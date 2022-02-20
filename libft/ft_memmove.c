/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:10:37 by joivanau          #+#    #+#             */
/*   Updated: 2021/11/05 16:06:36 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *d, const void *s, size_t len)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*str;

	i = -1;
	dest = (unsigned char *) d;
	str = (const unsigned char *) s;
	if (dest == NULL && str == NULL)
		return (NULL);
	if (d < s)
		while (++i < len)
			dest[i] = str[i];
	else
		while (len-- > 0)
			dest[len] = str[len];
	return (d);
}
