/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 17:46:55 by szeftyr           #+#    #+#             */
/*   Updated: 2020/10/06 13:37:03 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	inside_dir(t_list *file_list, t_flags *flags, int list_len)
{
	if (list_len > 1)
	{
		ft_putstr(((t_file *)file_list->content)->name);
		ft_putstr(":\n");
	}
	read_dir(((t_file *)file_list->content)->name, flags);
}

void	processor(t_list *file_list, t_flags *flags, int list_len)
{
	int	count;
	int	w[4];

	count = 0;
	ft_get_maxwidth(&file_list, w);
	while (file_list)
	{
		if (((((t_file *)file_list->content)->st.st_mode) & S_IFMT)
			== S_IFDIR)
		{
			if (count > 0)
				ft_putstr("\n");
			inside_dir(file_list, flags, list_len);
		}
		else
		{
			if (flags->l)
				display_full(file_list, flags, "", w);
			else
				ft_putstr(ft_strjoin(((t_file *)file_list->content)->name,
				"\n"));
		}
		file_list = file_list->next;
		count++;
	}
}

int		main(int argc, char **argv)
{
	t_flags		*flags;
	t_list		*file_list;
	int			list_len;

	flags = read_flags(argc, argv);
	file_list = create_file_list(argc, argv, flags);
	list_len = ft_lstlen(file_list);
	processor(file_list, flags, list_len);
	ft_lstdel(&file_list, &ft_lstfree);
	free(flags);
	return (0);
}
