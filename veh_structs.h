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

#endif