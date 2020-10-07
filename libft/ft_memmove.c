/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:28:47 by szeftyr           #+#    #+#             */
/*   Updated: 2019/09/19 09:37:45 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;

	if (!len)
		return (dst);
	if (!dst && !src)
		return (NULL);
	ptr_dst = (unsigned char*)dst;
	ptr_src = (unsigned char*)src;
	if (ptr_dst < ptr_src)
		return (ft_memcpy(dst, src, len));
	else
	{
		i = 0;
		while (i + 1 <= len)
		{
			ptr_dst[len - 1 - i] = ptr_src[len - 1 - i];
			i++;
		}
		return (dst);
	}
}
