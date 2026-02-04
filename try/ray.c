#include <stdio.h>

//https://www.youtube.com/watch?v=vYgIKn7iDH8

typedef struct s_pt
{
	double	x;
	double	y;
}				t_pt;

typedef	struct s_dir
{
	double	x;
	double	y;
}				t_dir;

typedef struct s_ray
{
	t_pt	*pos;
	t_dir	*dir;
}			t_ray;

typedef struct s_wall
{
	t_pt *pt1;
	t_pt *pt2;
}				t_wall;


/** ?? */
int	change_angle(t_dir *goal_dir, t_ray *ray)
{
	ray->dir->x = goal_dir->x - ray->pos->x;
	ray->dir->y = goal_dir->y - ray->pos->y; 
	//normalize(dirx, diry)
}


t_pt	*intersect_with_wall(t_wall *wall, t_ray *ray)
{	
	//int	x1 = wall->pt1->x;
	//int	y1 = wall->pt1->y;
	//int	x2 = wall->pt2->x;
	//int	y2 = wall->pt2->y;

	//int	x3 = ray->pos->x;
	//int	y3 = ray->pos->y;
	//int	x4 = ray->pos->x + ray->dir->x;
	//int	y4 = ray->pos->y + ray->dir->y;

	//y3 - y4 = -1 * ray->dir->x;
	//x3 - x4 = -1 * ray->dir->y;
	//int	den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

	t_pt	*pt;
	double	den;
	double	diff_x = wall->pt1->x - wall->pt2->x;
	double 	diff_y = wall->pt1->y - wall->pt2->y;
	double	diff_rayx = wall->pt1->x - ray->pos->x;
	double	diff_rayy = wall->pt1->y - ray->pos->y;
	den = diff_y * ray->dir->y - diff_x * ray->dir->x;
	if (den == 0)
		return (0); // paralle

	double	t = (diff_rayy * ray->dir->x - diff_rayx * ray->dir->y) / den;
	double	u = (diff_y * diff_rayx - diff_x * diff_rayy) / den;
	if (t > 0 && t < 1 && u > 0) // intersect
	{
		pt->x = wall->pt1->x + t * (wall->pt2->x - wall->pt1->x);
		pt->y = wall->pt1->y + t * (wall->pt2->y - wall->pt1->y);
		return (pt);
	}
	else
		return (0);
}

int	distance_cast_to_wall(t_wall *wall, t_ray *ray, char **map)
{
	t_pt	*pt;
	int		angle;
	int		res;

	angle = 0;
	while (angle < 360)
	{
		change_angle(dir_angle(angle), ray);
		res = 0;
		while (find_walls(map))
		{
			pt = intersect_with_wall(wall, ray);
			if (pt)
			{
				// check distance between the pt and position and use the shortest in the records.
				// res = distance(ray->x, ray->y, pt->x, pt->y);
			}
			get_next_wall(map);
		}
		if (res)
			//draw_line(res (ray->x, ray->y, pt->x, pt->y))
		angle += 10;
	}
}