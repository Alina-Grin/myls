/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:29:25 by szeftyr           #+#    #+#             */
/*   Updated: 2019/09/20 12:48:15 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_digit(unsigned int nbr)
{
	int	n_digit;

	n_digit = 1;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		n_digit++;
	}
	return (n_digit);
}

char		*ft_itoa(int n)
{
	char			*res;
	int				neg;
	int				i;
	unsigned int	nbr;

	neg = 1;
	if (n >= 0)
	{
		neg = 0;
		nbr = (unsigned int)n;
	}
	else
		nbr = (unsigned int)(-1 * n);
	i = ft_num_digit(nbr) + neg;
	if (!(res = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	res[i] = '\0';
	while (i-- != 0)
	{
		res[i] = (char)(nbr % 10 + 48);
		nbr = nbr / 10;
	}
	if (neg == 1)
		res[0] = '-';
	return (res);
}
