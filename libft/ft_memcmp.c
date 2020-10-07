/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:15:31 by szeftyr           #+#    #+#             */
/*   Updated: 2019/09/20 15:23:42 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_ptr;
	unsigned char	*s2_ptr;
	size_t			i;

	if (s1 == s2 || n == 0)
		return (0);
	i = 0;
	s1_ptr = (unsigned char*)s1;
	s2_ptr = (unsigned char *)s2;
	while (s1_ptr[i] == s2_ptr[i] && i < n)
	{
		i++;
		if (i == n)
			return (0);
	}
	return ((unsigned char)s1_ptr[i] - (unsigned char)s2_ptr[i]);
}
