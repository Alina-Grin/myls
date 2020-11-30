/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 13:32:44 by szeftyr           #+#    #+#             */
/*   Updated: 2020/10/11 13:33:00 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_stat(char *dirname, char *name, t_file *current)
{
	char	*abspath;

	abspath = NULL;
	current->name = ft_strdup(dirname);
	abspath = ft_path_join(name, current->name);
	lstat(abspath, &current->st);
	free(abspath);
}
