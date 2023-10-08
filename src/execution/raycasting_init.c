#include "../../cube3d.h"

void	ft_init_step(t_data *data, t_values *v)
{
	if (v->x_ray < 0)
	{
		v->step_x = -1;
		v->side_dist_x = (data->x_player - v->map_x) * v->delta_dist_x;
	}
	else
	{
		v->step_x = 1;
		v->side_dist_x = (v->map_x + 1 - data->x_player) * v->delta_dist_x;
	}
	if (v->y_ray < 0)
	{
		v->step_y = -1;
		v->side_dist_y = (data->y_player - v->map_y) * v->delta_dist_y;
	}
	else
	{
		v->step_y = 1;
		v->side_dist_y = (v->map_y + 1 - data->y_player) * v->delta_dist_y;
	}
}

void	ft_init_values(t_data *data, t_values *v, int i)
{
	v->map_x = (int)data->x_player;
	v->map_y = (int)data->y_player;
	v->x_ray = data->x_dir - data->x_plane + (i * 2 * data->x_plane / WIN_X);
	v->y_ray = data->y_dir - data->y_plane + (i * 2 * data->y_plane / WIN_X);
	v->delta_dist_x = 1e30;
	if (v->x_ray != 0)
		v->delta_dist_x
			= sqrt(1 + ((v->y_ray / v->x_ray) * (v->y_ray * v->x_ray)));
	v->delta_dist_y = 1e30;
	if (v->y_ray != 0)
		v->delta_dist_y
			= sqrt(1 + ((v->x_ray / v->y_ray) * (v->x_ray * v->y_ray)));
	ft_init_step(data, v);
	v->hit = 0;
}
