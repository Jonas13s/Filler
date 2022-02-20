/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:08:01 by joivanau          #+#    #+#             */
/*   Updated: 2021/12/03 03:05:16 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *d, const char *s, size_t dstsize)
{
	size_t		i;
	size_t		len_s;
	const char	*sc;

	i = 0;
	sc = (const char *) s;
	len_s = ft_strlen(sc);
	if (dstsize == 0)
		return (len_s);
	while (sc[i] && i < dstsize - 1)
	{
		d[i] = sc[i];
		i++;
	}
	d[i] = '\0';
	return (len_s);
}
