/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szeftyr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 13:15:55 by szeftyr           #+#    #+#             */
/*   Updated: 2020/10/11 10:51:03 by szeftyr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		unknown_flag(char c)
{
	ft_putstr_fd("ft_ls: unknown option -", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ft_ls [-alrRtcuUS] [file ...]\n", 2);
	exit(EXIT_FAILURE);
}

t_flags		*read_flags(int ac, char **av)
{
	int			i;
	int			j;
	t_flags		*flags;

	flags = ft_memalloc(sizeof(t_flags));
	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][0] == '-' && av[i][j++] != '\0')
		{
			if (!ft_strchr("alrRtcuUS", av[i][j]))
				unknown_flag(av[i][j]);
			flags->a = (av[i][j] == 'a' ? 1 : flags->a);
			flags->l = (av[i][j] == 'l' ? 1 : flags->l);
			flags->r = (av[i][j] == 'r' ? 1 : flags->r);
			flags->up_r = (av[i][j] == 'R' ? 1 : flags->up_r);
			flags->t = (av[i][j] == 't' ? 1 : flags->t);
			flags->c = (av[i][j] == 'c' ? 1 : flags->c);
			flags->u = (av[i][j] == 'u' ? 1 : flags->u);
			flags->up_u = (av[i][j] == 'U' ? 1 : flags->up_u);
			flags->up_s = (av[i][j] == 'S' ? 1 : flags->up_s);
		}
	}
	return (flags);
}

void		args_bolter(int ac, char **av, int *real_args, t_list **file_list)
{
	int				i;
	t_file			*tmp;
	struct stat		tbuf;

	tmp = (t_file *)ft_memalloc(sizeof(t_file));
	i = 0;
	while (++i < ac)
	{
		if (av[i][0] != '-' && lstat(av[i], &tbuf) == -1)
		{
			ft_putstr("ft_ls: ");
			print_error(av[i]);
			(*real_args)--;
		}
		else if (av[i][0] != '-' && !ft_strequ(av[i], "./ft_ls"))
		{
			tmp->name = ft_strdup(av[i]);
			lstat(tmp->name, &(tmp->st));
			ft_lstappend(file_list, ft_lstnew(tmp, sizeof(t_file)));
			(*real_args)++;
		}
	}
	free(tmp);
}

void		ft_lstmovend(t_list **head, int len)
{
	t_list	*curr;
	t_list	*old;
	t_list	*tmp;

	old = NULL;
	curr = *head;
	while (len-- > 0 && curr != NULL)
	{
		if ((((t_file *)curr->content)->st.st_mode & S_IFMT) == S_IFDIR)
		{
			if (curr->next == NULL)
				return ;
			if (old == NULL)
				*head = curr->next;
			else
				old->next = curr->next;
			moving(head, &curr, &tmp);
		}
		else
		{
			old = curr;
			curr = curr->next;
		}
	}
}

t_list		*create_file_list(int ac, char **av, t_flags *flags)
{
	t_list	*file_list;
	t_file	*tmp;
	int		real_args;
	int		i;
	int		len;

	i = 0;
	real_args = 0;
	file_list = NULL;
	tmp = (t_file *)ft_memalloc(sizeof(t_file));
	args_bolter(ac, av, &real_args, &file_list);
	if (real_args == 0 && !ft_lstlen(file_list))
	{
		tmp->name = ft_strdup(".");
		lstat(tmp->name, &(tmp->st));
		ft_lstappend(&file_list, ft_lstnew(tmp, sizeof(t_file)));
	}
	else
		sort_list(file_list, flags);
	if (flags->r)
		ft_lstrev(&file_list);
	len = ft_lstlen(file_list);
	ft_lstmovend(&file_list, len);
	free(tmp);
	return (file_list);
}
