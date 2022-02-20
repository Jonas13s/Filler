/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:07:48 by joivanau          #+#    #+#             */
/*   Updated: 2021/12/14 02:44:11 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strsplit_words(char const *s, char c)
{
	int	i;
	int	count;
	int	on;

	on = 1;
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			on = 1;
		if (s[i] != c && on == 1)
		{
			on = 0;
			count++;
		}
		i++;
	}
	return (count);
}

static int	strsplit_word_pos(char const *s, char c, int l)
{
	int	i;
	int	count;
	int	on;

	on = 1;
	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			on = 1;
		if (s[i] != c && on == 1)
		{
			on = 0;
			count++;
		}
		if (l == count)
			return (i);
		i++;
	}
	return (0);
}

static char	*strsplit_word(char const *s, char c, int l)
{
	int		i;
	int		k;
	char	*str;

	i = strsplit_word_pos(s, c, l);
	k = i;
	while (s[k] != c && s[k] != '\0')
		k++;
	str = ft_strsub(s, i, k - i);
	return (str);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		count;
	int		i;

	i = 1;
	if (!s)
		return (NULL);
	count = strsplit_words(s, c);
	str = (char **) malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (NULL);
	while (i <= count)
	{
		str[i - 1] = strsplit_word(s, c, i);
		i++;
	}
	str[i - 1] = NULL;
	return (str);
}
