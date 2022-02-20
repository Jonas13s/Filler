/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:29:56 by joivanau          #+#    #+#             */
/*   Updated: 2021/12/03 03:08:56 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t					i;
	const unsigned char		*s1s;
	const unsigned char		*s2s;

	s1s = (const unsigned char *) s1;
	s2s = (const unsigned char *) s2;
	i = 0;
	while (s1s[i] == s2s[i] && s1s[i] != '\0' && s2s[i] != '\0')
		i++;
	return (s1s[i] - s2s[i]);
}
