/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 11:29:24 by szeftyr           #+#    #+#             */
/*   Updated: 2020/10/13 11:41:51 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_dir(const char *path)
{
	struct stat statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (((statbuf.st_mode & S_IFMT) == S_IFDIR));
}

void		print_dir(t_list **entry, t_flags *flags, char *pname)
{
	t_list	*tmp;
	int		w[4];

	sort_list(*entry, flags);
	if (flags->r)
		ft_lstrev(entry);
	tmp = *entry;
	if (flags->l)
	{
		print_blocks(tmp);
		ft_get_maxwidth(&tmp, w);
		while (tmp)
		{
			display_full(tmp, flags, pname, w);
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp)
		{
			simple_print(((t_file *)tmp->content)->name);
			tmp = tmp->next;
		}
	}
}

void		rec_subdir(char *name, t_flags *flags)
{
	DIR				*dir;
	struct dirent	*pdir;
	char			*abspath;

	if (!(dir = opendir(name)))
		return (print_error(name));
	while ((pdir = readdir(dir)) != NULL && flags->up_r)
	{
		abspath = ft_path_join(name, pdir->d_name);
		if (flags->a && is_dir(abspath) && !ft_strequ(pdir->d_name, ".") &&
					!ft_strequ(pdir->d_name, ".."))
		{
			print_top(abspath);
			read_dir(abspath, flags);
		}
		if (is_dir(abspath) && !(ft_strncmp(pdir->d_name, ".", 1) == 0) &&
			!flags->a)
		{
			print_top(abspath);
			read_dir(abspath, flags);
		}
		free(abspath);
	}
	closedir(dir);
}

static void	free_entry(t_list *entry)
{
	t_list	*tmp;
	t_file	*tempos;

	while (entry != 0)
	{
		tmp = entry;
		entry = entry->next;
		if (tmp->content != 0)
		{
			tempos = (t_file *)tmp->content;
			free(tempos->name);
			free(tempos);
		}
		free(tmp);
	}
}

void		read_dir(char *name, t_flags *flags)
{
	DIR				*dir;
	struct dirent	*pdir;
	t_list			*entry;
	t_file			*current;

	entry = NULL;
	if (!(dir = opendir(name)))
		return (print_error(name));
	current = (t_file *)ft_memalloc(sizeof(t_file));
	while ((pdir = readdir(dir)) != NULL)
	{
		if (flags->a || pdir->d_name[0] != '.')
		{
			get_stat(pdir->d_name, name, current);
			ft_lstappend(&entry, ft_lstnew(current, sizeof(t_file)));
		}
	}
	if (entry)
		print_dir(&entry, flags, name);
	free_entry(entry);
	closedir(dir);
	rec_subdir(name, flags);
	free(current);
}
