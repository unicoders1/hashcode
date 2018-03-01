#ifndef VEH_H
# define VEH_H

# include "veh_structs.h"

/*
 * check_ride.c
 */

bool 	check_ride(t_vector *veh, t_vector *start, t_vector *end, int start_step, int end_step, int cur_step);
int		get_dist(t_vector *start, t_vector *end);

#endif