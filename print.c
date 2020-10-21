#include "ft_ls.h"

void	print_time(time_t mod_t)
{
	char	*str;
	char	*start;
	char	*end;
	time_t	ct;

	ct = time(NULL);
	if (!(str = ctime(&mod_t)))
		return ;
	start = str + 4;
	end = str + 10;
	*end = 0;
	ft_putstr(start);
	ft_putchar(' ');
	start = (mod_t > ct || mod_t + SIX_MONTHS < ct) ? str + 20 : str + 11;
	end = (mod_t > ct || mod_t + SIX_MONTHS < ct) ? str + 24 : str + 16;
	if (mod_t > ct || mod_t + SIX_MONTHS < ct)
		ft_putstr(" ");
	*end = 0;
	ft_putstr(start);
}

void	print_permissions(mode_t mode)
{
	ft_putchar((mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((mode & S_IWUSR) ? 'w' : '-');
	if (mode & S_ISUID)
		ft_putchar((mode & S_IXUSR) ? 's' : 'S');
	else
		ft_putchar((mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((mode & S_IWGRP) ? 'w' : '-');
	if (mode & S_ISGID)
		ft_putchar((mode & S_IXGRP) ? 's' : 'S');
	else
		ft_putchar((mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((mode & S_IROTH) ? 'r' : '-');
	ft_putchar((mode & S_IWOTH) ? 'w' : '-');
	if (mode & S_ISVTX)
		ft_putchar((mode & S_IXUSR) ? 't' : 'T');
	else
		ft_putchar((mode & S_IXOTH) ? 'x' : '-');
}

void	print_file_type(mode_t mode)
{
	if (((mode) & S_IFMT) == S_IFREG)
		ft_putchar('-');
	else if (((mode) & S_IFMT) == S_IFDIR)
		ft_putchar('d');
	else if (((mode) & S_IFMT) == S_IFCHR)
		ft_putchar('c');
	else if (((mode) & S_IFMT) == S_IFBLK)
		ft_putchar('b');
	else if (((mode) & S_IFMT) == S_IFIFO)
		ft_putchar('f');
	else if (((mode) & S_IFMT) == S_IFLNK)
		ft_putchar('l');
	else if (((mode) & S_IFMT) == S_IFSOCK)
		ft_putchar('s');
}

void	print_link(struct stat filestat, int w)
{
	int	len;
	int	dif;

	len = ft_ndigit(filestat.st_nlink);
	dif = w - len;
	while (dif > 0)
	{
		ft_putstr(" ");
		dif--;
	}
	ft_putnbr(filestat.st_nlink);
}

void	print_user_group(struct stat filestat, int w1, int w2)
{
	char	*userinfo;
	char	*groupinfo;
	int		len;
	int		dif;

	userinfo = (getpwuid(filestat.st_uid))->pw_name;
	len = ft_strlen(userinfo);
	dif = w1 - len;
	while (dif > 0)
	{
		ft_putstr(" ");
		dif--;
	}
	ft_putstr(userinfo);
	ft_putstr("  ");
	groupinfo = (getgrgid(filestat.st_gid))->gr_name;
	len = ft_strlen(groupinfo);
	dif = w2 - len;
	while (dif > 0)
	{
		ft_putstr(" ");
		dif--;
	}
	ft_putstr(groupinfo);
}
