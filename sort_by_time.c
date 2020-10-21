#include "ft_ls.h"

static time_t	get_time(t_file *f1, t_file *f2, t_flags *flags)
{
	if (flags->u)
	{
		if (f1->st.st_atimespec.tv_sec == f2->st.st_atimespec.tv_sec)
			return (f1->st.st_atimespec.tv_nsec - f2->st.st_atimespec.tv_nsec);
		else
			return (f1->st.st_atimespec.tv_sec - f2->st.st_atimespec.tv_sec);
	}
	else if (flags->c)
	{
		if (f1->st.st_ctimespec.tv_sec == f2->st.st_ctimespec.tv_sec)
			return (f1->st.st_ctimespec.tv_nsec - f2->st.st_ctimespec.tv_nsec);
		else
			return (f1->st.st_ctimespec.tv_sec - f2->st.st_ctimespec.tv_sec);
	}
	else if (flags->up_u)
		return (f1->st.st_birthtimespec.tv_sec == f2->st.st_birthtimespec.tv_sec
		?
		f1->st.st_birthtimespec.tv_nsec - f2->st.st_birthtimespec.tv_nsec :
		f1->st.st_birthtimespec.tv_sec - f2->st.st_birthtimespec.tv_sec);
	else
		return (f1->st.st_mtimespec.tv_sec == f2->st.st_mtimespec.tv_sec ?
			f1->st.st_mtimespec.tv_nsec - f2->st.st_mtimespec.tv_nsec :
			f1->st.st_mtimespec.tv_sec - f2->st.st_mtimespec.tv_sec);
}

static void		case_equal_time(t_list *p1, t_list *p2)
{
	if (((t_file *)p1->content)->name > ((t_file *)p2->content)->name)
		lst_swap(p1, p2);
}

void			sort_time(t_list **file_list, t_flags *flags)
{
	t_list		*prev;
	t_list		*ptr;
	time_t		time;
	int			swapped;

	prev = NULL;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr = *file_list;
		while (ptr->next != NULL)
		{
			if ((time = get_time(((t_file *)ptr->content),
				((t_file *)ptr->next->content), flags)) == 0)
				case_equal_time(ptr, ptr->next);
			if (time < 0)
			{
				lst_swap(ptr, ptr->next);
				swapped = 1;
			}
			ptr = ptr->next;
		}
		prev = ptr;
	}
}
