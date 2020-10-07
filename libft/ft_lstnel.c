/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:19:22 by szeftyr           #+#    #+#             */
/*   Updated: 2019/09/24 16:32:01 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnel(t_list *begin_list, unsigned int nbr)
{
	t_list			*tmp;
	unsigned int	i;

	if (!begin_list)
		return (NULL);
	if (nbr == 0)
		return (begin_list);
	tmp = begin_list;
	i = 0;
	while (tmp->next != NULL && i < nbr + 1)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}
