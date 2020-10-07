/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:47:08 by szeftyr           #+#    #+#             */
/*   Updated: 2019/09/20 19:54:14 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	char			*cpy;
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen((char *)s);
	res = (char *)ft_memalloc(len + 1);
	if (res == 0 || s == NULL)
		return (NULL);
	cpy = (char *)s;
	i = 0;
	while (cpy[i] != '\0')
	{
		res[i] = f(i, cpy[i]);
		i++;
	}
	return (res);
}
