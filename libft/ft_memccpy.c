/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:19:59 by szeftyr           #+#    #+#             */
/*   Updated: 2019/09/18 18:13:41 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *app, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char*)app)[i] == (unsigned char)c)
		{
			((unsigned char*)dst)[i] = ((unsigned char*)app)[i];
			return (dst + i + 1);
		}
		((unsigned char*)dst)[i] = ((unsigned char*)app)[i];
		i++;
	}
	return (NULL);
}
