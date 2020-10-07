/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 15:34:12 by szeftyr           #+#    #+#             */
/*   Updated: 2020/10/07 17:01:25 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_error(char *name)
{
	ft_putstr(ft_strjoin(name, ": "));
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	return ;
}

void	print_top(char *abspath)
{
	ft_putstr(ft_strjoin("\n", abspath));
	ft_putstr(":\n");
}

void	ft_get_maxwidth(t_list **begin, int *w)
{
	int		len;
	t_list	*tmp;

	ft_bzero(w, sizeof(int) * 4);
	tmp = *begin;
	while (tmp)
	{
		len = (ft_ndigit(((t_file *)tmp->content)->st.st_nlink));
		w[0] = ((len > w[0]) ? len : w[0]);
		len = ft_strlen(getpwuid(((t_file *)tmp->content)->st.st_uid)->pw_name);
		w[1] = ((len > w[1]) ? len : w[1]);
		len = ft_strlen(getgrgid(((t_file *)tmp->content)->st.st_gid)->gr_name);
		w[2] = ((len > w[2]) ? len : w[2]);
		len = (ft_ndigit(((t_file *)tmp->content)->st.st_size));
		w[3] = ((len > w[3]) ? len : w[3]);
		tmp = tmp->next;
	}
	tmp = NULL;
}

// void	ft_get_maxwidth(t_list **begin, int *w)
// {
// 	int		len;

// 	ft_bzero(w, sizeof(int) * 4);
// 	while ((*begin))
// 	{
// 		len = (ft_ndigit(((t_file *)(*begin)->content)->st.st_nlink));
// 		w[0] = ((len > w[0]) ? len : w[0]);
// 		len = ft_strlen(getpwuid(((t_file *)(*begin)->content)->st.st_uid)->pw_name);
// 		w[1] = ((len > w[1]) ? len : w[1]);
// 		len = ft_strlen(getgrgid(((t_file *)(*begin)->content)->st.st_gid)->gr_name);
// 		w[2] = ((len > w[2]) ? len : w[2]);
// 		len = (ft_ndigit(((t_file *)(*begin)->content)->st.st_size));
// 		w[3] = ((len > w[3]) ? len : w[3]);
// 		(*begin) = (*begin)->next;
// 	}
// }
