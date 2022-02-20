/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:23:25 by joivanau          #+#    #+#             */
/*   Updated: 2021/12/03 03:06:52 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *d, const char *s, size_t size)
{
	size_t		returnvalue;
	size_t		len_d;
	size_t		len_s;

	len_d = ft_strlen(d);
	len_s = ft_strlen(s);
	if (size > len_d)
		returnvalue = len_d + len_s;
	else
		returnvalue = len_s + size;
	len_s = 0;
	while (s[len_s] && (len_d + 1) < size)
	{
		d[len_d] = s[len_s];
		len_s++;
		len_d++;
	}
	d[len_d] = '\0';
	return (returnvalue);
}
