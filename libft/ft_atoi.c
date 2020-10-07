/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:40:00 by szeftyr           #+#    #+#             */
/*   Updated: 2019/09/21 13:24:40 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long long int	nb;
	int						negative;

	nb = 0;
	while (*str != '\0' && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\r' || *str == '\f'))
		str++;
	negative = 1;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10;
		nb = nb + (unsigned long long int)(*str - 48);
		str++;
	}
	if (negative == 1 && nb > 9223372036854775807)
		return (-1);
	else if (negative == -1 && nb > 2147483648)
		return (0);
	else
		return (negative * nb);
}
