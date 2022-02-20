/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:01:08 by joivanau          #+#    #+#             */
/*   Updated: 2021/12/03 03:18:52 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, \
int c, size_t n)
{
	size_t					i;
	unsigned char			*des;
	const unsigned char		*str;

	des = (unsigned char *) dest;
	str = (const unsigned char *) src;
	i = 0;
	while (i < n)
	{
		des[i] = str[i];
		if (str[i] == (unsigned char) c)
			return (des + i + 1);
		i++;
	}
	return (NULL);
}
