/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:56:22 by joivanau          #+#    #+#             */
/*   Updated: 2021/11/11 14:27:34 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_memcpy(void *d, const void *s, size_t n)
{
	unsigned int		i;
	unsigned char		*dest;
	unsigned char const	*str;

	dest = (unsigned char *) d;
	str = (unsigned const char *) s;
	i = -1;
	if (d == NULL && s == NULL)
		return (NULL);
	while (++i < n)
		dest[i] = str[i];
	return (d);
}
