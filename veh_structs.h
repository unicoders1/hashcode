#ifndef VEH_STRUCTS_H
# define VEH_STRUCTS_H

# define ABS(x) ((x < 0) ? (-x) : x)

typedef struct
{
	int x;
	int y;
}	t_vector;

typedef struct
{
	int		start;
	int		finish;
}			t_vehicle;

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
	t_vector	start;
	t_vector	end;
	int     	early;
	int     	finish;
}               t_ride;

typedef struct  s_ride_params
{
	int     	dist;
	int			dist_rest;
	int			step_end;
	int			max_dist;
	int			next_step;
	t_vector	end;
	t_ride		next;
	bool		is_bonus;
}               t_ride_params;

typedef struct  s_ride_params
{
	int			score;
	int			next_step;
	t_vector	next_veh;
}               t_ride_params;


typedef    struct        s_list
{
	t_ride           	*rides;
	int				  	dist;
	struct s_list		*next;
}                    t_list;

#endif