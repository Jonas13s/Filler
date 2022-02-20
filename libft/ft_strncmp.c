/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 15:35:30 by joivanau          #+#    #+#             */
/*   Updated: 2021/12/03 03:00:37 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned const char	*s1s;
	unsigned const char	*s2s;
	size_t				i;

	s1s = (unsigned const char *) s1;
	s2s = (unsigned const char *) s2;
	i = 0;
	while (s1s[i] == s2s[i] && s1s[i] != '\0' && \
	s2s[i] != '\0' && i < n - 1)
	{
		if (s1s[i] != s2s[i])
			break ;
		else
			i++;
	}
	if (n == 0)
		return (0);
	return (s1s[i] - s2s[i]);
}
