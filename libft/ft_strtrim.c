/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 12:28:29 by joivanau          #+#    #+#             */
/*   Updated: 2021/11/12 12:31:21 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fts_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

static int	ft_whitespaceend(char const *s)
{
	int		i;
	int		k;

	i = 0;
	while (s[i] != '\0')
	{
		k = i;
		while (fts_isspace(s[k]) == 1)
		{
			k++;
			if (s[k] == '\0')
				return (i);
		}
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s)
{
	int		i;
	char	*str;
	int		k;
	int		x;

	x = 0;
	if (!s)
		return (NULL);
	i = 0;
	while (fts_isspace(s[i]) == 1)
		i++;
	k = ft_whitespaceend(s);
	if (k > i)
		str = (char *) malloc(sizeof(char) * (k - i + 1));
	else
		str = (char *) malloc(sizeof(char) * (i - k + 1));
	if (!str)
		return (NULL);
	while (i < k)
		str[x++] = s[i++];
	str[x] = '\0';
	return (str);
}
