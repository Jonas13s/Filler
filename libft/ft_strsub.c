/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:32:44 by joivanau          #+#    #+#             */
/*   Updated: 2021/12/03 03:01:22 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	x;

	if (!s)
		return (NULL);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	x = 0;
	i = start;
	while (x < len)
	{
		str[x] = s[i];
		x++;
		i++;
	}
	str[x] = '\0';
	return (str);
}
