#ifndef FT_LS_H
# define FT_LS_H
# define SIX_MONTHS 15552000

# include <sys/types.h>
# include <string.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <unistd.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <stdlib.h>
# include <stdbool.h>
# include <errno.h>
# include <sys/xattr.h>
# include "libft/libft.h"

typedef struct		s_flags
{
	bool			l;
	bool			up_r;
	bool			a;
	bool			r;
	bool			t;
	bool			c;
	bool			u;
	bool			up_u;
	bool			up_s;
}					t_flags;

typedef struct		s_file
{
	char			*name;
	struct stat		st;
}					t_file;

void				unknown_flag(char c);
void				moving(t_list **head, t_list **curr, t_list **tmp);
t_flags				*read_flags(int ac, char **argv);
t_list				*create_file_list(int ac, char **av, t_flags *flags);
char				*ft_path_join(const char *path, const char *file_name);
void				lst_swap(t_list *p1, t_list *p2);
void				sort_list(t_list *file_list, t_flags *flags);
void				sort_time(t_list **file_list, t_flags *flags);
void				processor(t_list *file_list, t_flags *flags, int list_len);
void				print_blocks(t_list *file_list);
void				print_time(time_t mod_time);
void				print_file_type(mode_t mode);
void				print_permissions(mode_t mode);
void				print_link(struct stat filestat, int w);
void				print_user_group(struct stat filestat, int w1, int w2);
void				display_full(t_list *file_list, t_flags *flags, char *name,
								int *w);
void				read_dir(char *name, t_flags *flags);
void				print_dir(t_list **entry, t_flags *flags, char *name);
void				print_error(char *name);
void				print_top(char	*abspath);
void				simple_print(char *str);
void				ft_get_maxwidth(t_list **begin, int *w);
void				get_stat(char *dirname, char *name, t_file *current);

#endif
