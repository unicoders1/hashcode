#ifndef VEH_H
# define VEH_H

# include "veh_structs.h"

/*
 * global_variables
 */

t_ride *rides;
t_info info;


/*
 * check_ride.c
 */

t_ride_params 	check_ride(t_vector *veh, t_ride *ride, int cur_step);
int				get_dist(t_vector *start, t_vector *end);

/*
 * rides_iter.c
 */

void		rides_iter(t_list **l_rides, int cur_step, t_vector *veh);

/*
 * ft_list_pushback.c
 */

void	ft_list_pushback(t_list **alst, t_list *new)

#endif