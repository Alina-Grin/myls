/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:24:58 by szeftyr           #+#    #+#             */
/*   Updated: 2019/09/18 16:39:15 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *app, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_app;
	size_t			i;

	if (!n || dst == app)
		return (dst);
	ptr_dst = (unsigned char*)dst;
	ptr_app = (unsigned char*)app;
	i = 0;
	while (i < n)
	{
		ptr_dst[i] = ptr_app[i];
		i++;
	}
	return (dst);
}
