/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:57:57 by joivanau          #+#    #+#             */
/*   Updated: 2021/12/03 03:16:10 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	str = (const unsigned char *) s;
	i = -1;
	while (++i < n)
		if (str[i] == (unsigned char) c)
			return ((void *)s + i);
	return (NULL);
}
