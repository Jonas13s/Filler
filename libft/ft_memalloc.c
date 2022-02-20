/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:48:23 by joivanau          #+#    #+#             */
/*   Updated: 2021/11/25 15:24:46 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	str = (void *) malloc(sizeof(void) * size);
	if (!(str))
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
