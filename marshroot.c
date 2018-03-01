
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
    int     r_start;
    int     c_start;
    int     r_end;
    int     c_end;
    int     early;
    int     finish;
    int     steps;
}               t_ride;

typedef struct  s_ride_params
{
    int     	dist;
    int			dist_rest;
    int			step_end;
    t_vector	end;
    t_ride		next;
    bool		is_bonus;
}               t_ride_params;

t_ride *rides;
t_info info;

t_ride_params	set_ride_params(t_ride *ride, t_vector *veh)
{

}

t_list find_small_marshroot()
{
	for (int i = 0; i < info.rides; ++i)

}