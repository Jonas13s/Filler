/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 16:37:08 by joivanau          #+#    #+#             */
/*   Updated: 2021/12/03 03:44:13 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
		return (new);
	}
	if (content)
	{
		new->content = (void *) malloc(sizeof(void) * content_size);
		if (!new->content)
		{
			free(new);
			return (new);
		}
		new->content_size = content_size;
		new->content = ft_memcpy(new->content, content, content_size);
	}
	new->next = NULL;
	return (new);
}
