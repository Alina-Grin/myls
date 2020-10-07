/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 17:54:43 by szeftyr           #+#    #+#             */
/*   Updated: 2019/09/21 18:08:27 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*ptr;

	if (!alst || !*alst)
		return ;
	ptr = *alst;
	if (del)
	{
		while (ptr)
		{
			tmp = ptr->next;
			ft_lstdelone(&ptr, del);
			ptr = tmp;
		}
	}
	*alst = NULL;
}
