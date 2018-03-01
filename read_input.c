#include <stdio.h>
#include <stdlib.h>


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

void    adding_to_list(t_list **l_rides, t_ride *ride, int dist);

int     main(int ac, char **argv)
{
    char *first = NULL;
    t_info info;
    t_ride *rides = NULL;
    FILE *fp;
    t_list *l_rides = NULL;

    fp = fopen(argv[1], "r");

    fscanf(fp, "%d %d %d %d %d %d", &info.rows, &info.columns, &info.vehicles, &info.rides, &info.bonus, &info.steps);
    rides = (t_ride*)malloc(sizeof(t_ride) * (info.rides));
    while (fscanf(fp, "%d %d %d %d %d %d",\
     &rides->start.y, &rides->start.x,&rides->end.y,&rides->end.x,&rides->early,&rides->finish) != -1)
    {
        // printf("rides->start.y%d\n", rides->start.y);
        adding_to_list(&l_rides, rides, rides->early);
        rides++;
    }
}