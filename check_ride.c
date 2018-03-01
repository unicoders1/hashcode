#include <stdbool.h>
#include "veh.h"

int		get_dist(t_vector *start, t_vector *end)
{
	return (ABS(end->x - start->x) + ABS(end->y - start->y));
}

static int		get_next_step(t_vector *veh, t_ride *ride, int cur_step)
{
	if (get_dist(veh, ride->start) < ride->start - cur_step)
		return (ride->start + get_dist(ride->start, ride->end));
	return (cur_step + get_dist(ride->start, ride->end) + get_dist(veh, ride->start));
}

t_ride_params 	check_ride(t_vector *veh, t_ride *ride, int cur_step)
{
	int	dist_to_start = get_dist(veh, ride->start);
	int	dist_to_end = get_dist(ride->start, ride->end);
	t_ride_params *ride_params = (t_ride_params*)malloc(sizeof(t_ride_params));

	ride_params->score = 0;
	if (ride->finish - cur_step >= dist_to_start + dist_to_end) {
		if (dist_to_start <= ride->early - cur_step)
			ride_params->score += info.bonus;
		ride_params->score += dist_to_end;
		ride_params->next_step = get_next_step(veh, ride, cur_step);
		ride_params->next_veh = ride->end;
		return ride_params;
	}
	free(ride_params);
	return NULL;
}
