/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 09:58:32 by szeftyr           #+#    #+#             */
/*   Updated: 2019/09/23 11:59:05 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*node;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = f(lst);
	node = ft_lstnew(tmp->content, tmp->content_size);
	if (!node)
		return (NULL);
	new_lst = node;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		node->next = ft_lstnew(tmp->content, tmp->content_size);
		if (!node->next)
			return (NULL);
		lst = lst->next;
		node = node->next;
	}
	return (new_lst);
}
