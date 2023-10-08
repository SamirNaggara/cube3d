#include "../../cube3d.h"

static void	tmp_init(t_data *data)
{
	data->x_player = 5.5;
	data->y_player = 8.5;
	data->x_dir = 1;
	data->y_dir = 0;
	data->x_plane = 0;
	data->y_plane = 0.66;
}

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
}

void	ft_raycasting(t_data *data)
{
	t_values	v;
	int			i;

	i = 0;
	tmp_init(data);
	while (i < WIN_X)
	{
		ft_init_values(data, &v, i);
		ft_algorithm(data, &v);
		i++;
	}
}
