/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:21:01 by joivanau          #+#    #+#             */
/*   Updated: 2021/11/10 16:10:08 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *d, const char *s)
{
	int	x;
	int	i;

	i = 0;
	x = ft_strlen(d);
	while (s[i] != '\0')
	{
		d[x + i] = s[i];
		i++;
	}
	d[x + i] = '\0';
	return (d);
}
