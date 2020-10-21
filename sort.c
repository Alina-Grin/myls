#include "ft_ls.h"

void		moving(t_list **head, t_list **curr, t_list **tmp)
{
	t_list	*tail;

	*tmp = *curr;
	*curr = (*curr)->next;
	tail = ft_lstlast(*head);
	tail->next = *tmp;
	(*tmp)->next = NULL;
	(*tmp) = NULL;
}

void		lst_swap(t_list *p1, t_list *p2)
{
	void		*tmp;

	tmp = p1->content;
	p1->content = p2->content;
	p2->content = tmp;
}

static void	sort_alpha(t_list *file_list)
{
	int		swapped;
	t_list	*ptr;
	t_list	*lptr;

	lptr = NULL;
	if (file_list == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr = file_list;
		while (ptr->next != lptr)
		{
			if (ft_strcmp(((t_file *)ptr->content)->name,
				((t_file *)ptr->next->content)->name) > 0)
			{
				lst_swap(ptr, ptr->next);
				swapped = 1;
			}
			ptr = ptr->next;
		}
		lptr = ptr;
	}
}

static void	sort_size(t_list *file_list)
{
	int		swapped;
	t_list	*ptr;
	t_list	*lptr;

	lptr = NULL;
	if (file_list == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr = file_list;
		while (ptr->next != lptr)
		{
			if (((t_file *)ptr->content)->st.st_size <
				((t_file *)ptr->next->content)->st.st_size)
			{
				lst_swap(ptr, ptr->next);
				swapped = 1;
			}
			ptr = ptr->next;
		}
		lptr = ptr;
	}
}

void		sort_list(t_list *file_list, t_flags *flags)
{
	if (flags->up_s)
		sort_size(file_list);
	else if (flags->t)
		sort_time(&file_list, flags);
	else
		sort_alpha(file_list);
}
