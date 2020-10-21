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
