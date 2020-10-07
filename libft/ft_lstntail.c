/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstntail.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:24:44 by szeftyr           #+#    #+#             */
/*   Updated: 2019/09/24 17:24:48 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstntail(t_list **list, void const *cont, size_t c_size)
{
	t_list	*tmp;
	t_list	*tail;

	if (!*list || !cont || !c_size)
		return ;
	tmp = ft_lstnew(cont, c_size);
	tail = ft_lstlast(*list);
	tail->next = tmp;
}
