/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:12:03 by joivanau          #+#    #+#             */
/*   Updated: 2021/11/12 12:31:23 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
