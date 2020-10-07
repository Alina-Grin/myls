/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:01:44 by szeftyr           #+#    #+#             */
/*   Updated: 2019/09/21 17:06:00 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	if (*find == '\0')
		return ((char *)str);
	if (len == 0)
		return (NULL);
	j = 0;
	while (str[j] != '\0' && j < len)
	{
		if (str[j] == find[0])
		{
			i = 1;
			while (str[j + i] == find[i] &&
					find[i] != '\0' && (j + i) < len)
				i++;
			if (find[i] == '\0')
				return ((char *)&str[j]);
		}
		j++;
	}
	return (NULL);
}
