/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:32:33 by szeftyr           #+#    #+#             */
/*   Updated: 2019/09/20 19:53:10 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*res;
	char			*cpy;
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen((char *)s);
	res = (char *)ft_memalloc(len + 1);
	if (res == 0)
		return (NULL);
	cpy = (char *)s;
	i = 0;
	while (cpy[i] != '\0')
	{
		res[i] = f(cpy[i]);
		i++;
	}
	return (res);
}
