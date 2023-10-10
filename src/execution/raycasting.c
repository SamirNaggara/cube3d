#include "cube3d.h"

void	ft_algorithm(t_data *data, t_values *v)
{
	while (v->hit == 0)
	{
		if (v->side_dist_x < v->side_dist_y)
		{
			v->side_dist_x += v->delta_dist_x;
			v->map_x += v->step_x;
			v->side = 0;
		}
		else
		{
			v->side_dist_y += v->delta_dist_y;
			v->map_y += v->step_y;
			v->side = 1;
		}
		if (data->map[v->map_y][v->map_x] == '1')
			v->hit = 1;
	}
	if (v->side == 0)
		v->wall_dist = v->side_dist_x - v->delta_dist_x;
	else
		v->wall_dist = v->side_dist_y - v->delta_dist_y;
}

void	ft_raycasting(t_data *data)
{
	t_values	v;
	int			x;

	x = 0;
	while (x < WIN_X)
	{
		ft_init_values(data, &v, x);
		ft_algorithm(data, &v);
		ft_draw(data, &v, x);
		x++;
	}
	mlx_put_image_to_window
		(data->mlx, data->window, data->screen.img_ptr, 0, 0);
}
