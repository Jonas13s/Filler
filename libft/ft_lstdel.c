/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:18:15 by joivanau          #+#    #+#             */
/*   Updated: 2021/11/11 18:37:57 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*head;

	tmp = *alst;
	if (tmp != NULL)
	{
		while (tmp)
		{
			head = tmp->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
			tmp = head;
		}
		*alst = NULL;
	}
}
