/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 11:29:24 by szeftyr           #+#    #+#             */
/*   Updated: 2020/10/10 14:58:34 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*ft_path_join(const char *path, const char *file_name)
{
	char	*abspath;
	size_t	path_len;

	path_len = ft_strlen(path);
	abspath = ft_strnew(path_len + ft_strlen(file_name) + 1);
	if (abspath == NULL)
		return (NULL);
	ft_strcpy(abspath, path);
	if (path_len > 0 && abspath[path_len - 1] != '/')
		abspath[path_len++] = '/';
	ft_strcat(abspath, file_name);
	return (abspath);
}

static int	is_dir(const char *path)
{
	struct stat statbuf;

	if (stat(path, &statbuf) != 0)
		return (0);
	return (((statbuf.st_mode & S_IFMT) == S_IFDIR));
}

void		print_dir(t_list *entry, t_flags *flags, char *pname)
{
	t_list	*tmp;
	int		w[4];

	tmp = entry;
	sort_list(tmp, flags);
	if (flags->r)
		ft_lstrev(&tmp);
	if (flags->l)
	{
		print_blocks(tmp);
		ft_get_maxwidth(&entry, w);
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
			ft_putstr(ft_strjoin(((t_file *)tmp->content)->name, "\n"));
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

void		read_dir(char *name, t_flags *flags)
{
	DIR				*dir;
	struct dirent	*pdir;
	t_list			*entry;
	t_file			*current;
	char			*abspath;

	abspath = NULL;
	entry = NULL;
	current = (t_file *)ft_memalloc(sizeof(t_file));
	if (!(dir = opendir(name)))
		return (print_error(name));
	while ((pdir = readdir(dir)) != NULL)
	{
		if (flags->a || pdir->d_name[0] != '.')
		{
			current->name = ft_strdup(pdir->d_name);
			abspath = ft_path_join(name, current->name);
			lstat(abspath, &current->st);
			// ft_lstntail(&entry, current, sizeof(t_file));
			ft_lstappend(&entry, ft_lstnew(current, sizeof(t_file)));
			free(abspath);
		}
	}
	print_dir(entry, flags, name);
	closedir(dir);
	rec_subdir(name, flags);
	free(current);
}
