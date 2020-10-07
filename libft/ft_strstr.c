/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:17:04 by szeftyr           #+#    #+#             */
/*   Updated: 2019/09/19 15:50:56 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int	j;

	j = 0;
	if (*to_find == '\0')
		return ((char *)str);
	while (str[j] != '\0')
	{
		if (str[j] == to_find[0])
		{
			i = 1;
			while ((str[j + i] == to_find[i]) && (to_find[i] != '\0'))
				i++;
			if (to_find[i] == '\0')
				return ((char *)&str[j]);
		}
		j++;
	}
	return (NULL);
}
