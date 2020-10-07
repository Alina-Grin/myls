/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shakersort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:03:44 by szeftyr           #+#    #+#             */
/*   Updated: 2020/09/23 13:58:25 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_shakersort(int *a, int n)
{
	int left;
	int	right;
	int	i;

	left = 0;
	right = n - 1;
	while (left <= right)
	{
		i = right;
		while (i >= left)
		{
			if (a[i - 1] > a[i])
				ft_swap(&a[i - 1], &a[i]);
			i--;
		}
		left++;
		i = left;
		while (i <= right)
		{
			if (a[i - 1] > a[i])
				ft_swap(&a[i - 1], &a[i]);
			i++;
		}
		right--;
	}
}
