#include "ft_ls.h"

char	*ft_path_join(const char *path, const char *file_name)
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

void	print_error(char *name)
{
	char	*str;

	str = ft_strjoin(name, ": ");
	ft_putstr(str);
	ft_putstr(strerror(errno));
	ft_putstr("\n");
	free(str);
	return ;
}

void	print_top(char *abspath)
{
	char	*str;

	str = ft_strjoin("\n", abspath);
	ft_putstr(str);
	free(str);
	ft_putstr(":\n");
}

void	simple_print(char *str)
{
	char	*tmp;

	tmp = ft_strjoin(str, "\n");
	ft_putstr(tmp);
	free(tmp);
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
