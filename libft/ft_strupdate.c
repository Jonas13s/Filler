/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupdate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:25:10 by joivanau          #+#    #+#             */
/*   Updated: 2021/11/30 02:23:05 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupdate(char *s1, const char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	if (!temp)
		return (NULL);
	ft_strdel(&s1);
	return (temp);
}
