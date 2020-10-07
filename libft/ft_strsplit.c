/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:22:51 by szeftyr           #+#    #+#             */
/*   Updated: 2019/09/21 15:38:56 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordc(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] != c && str[0] != '\0')
		count++;
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

static int	ft_wlen(char const *str, char c)
{
	int i;
	int len_w;

	i = 0;
	len_w = 0;
	while (str[i] == c && str[i] != '\0')
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		len_w++;
		i++;
	}
	return (len_w);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		j;
	int		wordc;

	if (!s)
		return (NULL);
	wordc = ft_wordc((char *)s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (wordc + 1))))
		return (NULL);
	j = 0;
	while (*s != '\0' && j < wordc)
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s != c && *s != '\0')
		{
			arr[j] = ft_strsub(s, 0, ft_wlen(s, c));
			s = s + ft_wlen(s, c);
		}
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
