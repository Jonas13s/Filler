/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:59:54 by joivanau          #+#    #+#             */
/*   Updated: 2021/11/12 12:01:22 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*head;

	if (!lst && !f)
		return (NULL);
	temp = ft_lstnew(f(lst)->content, f(lst)->content_size);
	if (!temp)
		return (NULL);
	head = temp;
	while (lst->next)
	{
		lst = lst->next;
		temp->next = ft_lstnew(f(lst)->content, f(lst)->content_size);
		if (!temp)
			return (NULL);
		temp = temp->next;
	}
	return (head);
}
