/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:04:41 by szeftyr           #+#    #+#             */
/*   Updated: 2020/10/03 20:09:39 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup_src;
	int		i;

	dup_src = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dup_src == 0)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dup_src[i] = src[i];
		i++;
	}
	dup_src[i] = '\0';
	return (dup_src);
}
