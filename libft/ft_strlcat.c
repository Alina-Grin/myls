/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:21:25 by szeftyr           #+#    #+#             */
/*   Updated: 2019/09/20 17:38:52 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *append, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	total;

	i = ft_strlen(dest);
	total = ft_strlen(append);
	if (i >= size)
		total = total + size;
	else
		total = total + i;
	j = 0;
	while (i + 1 < size && append[j] != '\0')
	{
		dest[i] = append[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (total);
}
