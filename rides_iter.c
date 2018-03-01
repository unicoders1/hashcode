#include "veh.h"

void		rides_iter(t_list **l_rides, int cur_step, t_vector *veh)
{
	t_ride_params	*ride_params;
	int				dist;

	for (int i = 0; i < info.rides; ++i) {
		if ((ride_params = check_ride(veh, &(rides[i]), cur_step)))
		{
			if (get_dist(veh, ride->start) <= ride->early - cur_step)
				dist = ride->early - cur_step;
			else
				dist = get_dist(veh, ride->start);
			adding_to_list(ride, dist, ride_params);
		}
	}
}
