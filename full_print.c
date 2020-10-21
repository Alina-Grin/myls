#include "ft_ls.h"

static void	print_size_or_dev(struct stat filestat, int w)
{
	int	len;
	int	dif;

	if ((filestat.st_mode & S_IFMT) == S_IFCHR
		|| (filestat.st_mode & S_IFMT) == S_IFBLK)
	{
		ft_putnbr((int32_t)(((u_int32_t)(filestat.st_rdev) >> 24) & 0xff));
		ft_putstr(", ");
		ft_putnbr((int32_t)((filestat.st_rdev) & 0xffffff));
	}
	else
	{
		len = ft_ndigit(filestat.st_size);
		dif = w - len;
		while (dif > 0)
		{
			ft_putstr(" ");
			dif--;
		}
		ft_putnbr(filestat.st_size);
	}
}

static void	print_lorn(t_list *file_list, char *parent)
{
	char	buf[1024];
	ssize_t	len;
	char	*abspath;

	len = 0;
	abspath = NULL;
	ft_putstr(((t_file *)file_list->content)->name);
	abspath = ft_path_join(parent, ((t_file *)file_list->content)->name);
	if ((((t_file *)file_list->content)->st.st_mode & S_IFMT) == S_IFLNK)
	{
		len = readlink(abspath, buf, 1024);
		if (len != -1)
		{
			buf[len] = '\0';
			ft_putstr(" -> ");
			ft_putstr(buf);
		}
	}
	free(abspath);
}

void		print_blocks(t_list *file_list)
{
	blkcnt_t	total;

	total = 0;
	while (file_list)
	{
		total += ((t_file *)file_list->content)->st.st_blocks;
		file_list = file_list->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putstr("\n");
}

void		print_xattr(t_list *file_list, char *parent)
{
	ssize_t	n;
	char	list[512];
	char	*abspath;

	abspath = NULL;
	abspath = ft_path_join(parent, ((t_file *)file_list->content)->name);
	n = listxattr(abspath, list, 512, XATTR_NOFOLLOW);
	if (n > 0)
		ft_putstr("@");
	else
		ft_putstr(" ");
	ft_putstr(" ");
	free(abspath);
}

void		display_full(t_list *file_list, t_flags *flags, char *name, int *w)
{
	time_t	prtime;

	if (flags->u)
		prtime = ((t_file *)file_list->content)->st.st_atime;
	else if (flags->c)
		prtime = ((t_file *)file_list->content)->st.st_ctime;
	else if (flags->up_u)
		prtime = ((t_file *)file_list->content)->st.st_birthtimespec.tv_sec;
	else
		prtime = ((t_file *)file_list->content)->st.st_mtime;
	print_file_type(((t_file *)file_list->content)->st.st_mode);
	print_permissions(((t_file *)file_list->content)->st.st_mode);
	print_xattr(file_list, name);
	print_link(((t_file *)file_list->content)->st, w[0]);
	ft_putstr(" ");
	print_user_group(((t_file *)file_list->content)->st, w[1], w[2]);
	ft_putstr("  ");
	print_size_or_dev(((t_file *)file_list->content)->st, w[3]);
	ft_putstr(" ");
	print_time(prtime);
	ft_putchar(' ');
	print_lorn(file_list, name);
	ft_putstr("\n");
}
