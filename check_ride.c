#include <stdbool.h>
#include "veh.h"

bool 	check_ride(t_vector *veh, t_vector *start, t_vector *end, int start_step, int end_step, int cur_step)
{
	int	dist_to_start = ABS(start->x - veh->x) + ABS(start->y - veh->y);
	int	dist_to_end = ABS(end->x - start->x) + ABS(end->y - start->y);

	if (end_step - cur_step >= dist_to_start + dist_to_end)
		return true;
	return false;
}
