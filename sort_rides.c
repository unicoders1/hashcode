typedef struct  s_vector
{
    int     x;
    int     y;
}               t_vector;

typedef struct  s_info
{
    int     rows;
    int     columns;
    int     vehicles;
    int     rides;
    int     bonus;
    int     steps;

}               t_info;

typedef struct  s_ride
{
    t_vector start;
    t_vector end;
    int     early;
    int     finish;
}               t_ride;

typedef struct      s_list
{
    t_ride          *ride;
    int             dist;
    struct s_list   *next;
}                   t_list;

void	dr_lst_add(t_list **begin, t_list *new)
{
	if (begin && new)
	{
		new->next = *begin;
		*begin = new;
	}
}

void	dr_lst_insert(t_list *first, t_list *second, t_list *new)
{
	first->next = new;
	new->next = second;
}

t_list	*dr_lst_new(t_ride *ride, int dist)
{
	t_list		*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->ride = ride;
	new->dist = dist;
	new->next = NULL;
	return (new);
}

void	adding_to_list(t_list **l_rides, t_ride *ride, int dist)
{
	t_list			*ptr;
	t_list			*ptr2 = NULL;

	ptr = *l_rides;
	if (*l_rides == NULL)
		dr_lst_add(l_rides, dr_lst_new(ride, dist));
	else
	{
		while (ptr != NULL)
		{
			if (dist < ptr->dist)
			{
				dr_lst_add(l_rides, dr_lst_new(ride, dist));
				break ;
			}
			ptr2 = ptr->next;
			if (ptr2 != NULL && dist <= ptr2->dist)
			{
				dr_lst_insert(ptr, ptr->next, dr_lst_new(ride, dist));
				break ;
			}
			if (ptr->next == NULL)
			{
				ptr->next = dr_lst_new(ride, dist);
				break ;
			}
			ptr = ptr->next;
		}
	}
}