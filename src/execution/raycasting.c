#include "../../cube3d.h"

typedef struct	s_values
{
	double	x_ray;
	double	y_ray;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		hit;
	int		side;
}	t_values;

static void	tmp_init(t_data *data)
{
	data->x_dir = 1;
	data->y_dir = 0;
	data->x_plane = 0;
	data->y_plane = 0.66;
}

void	ft_init_values(t_data *data, t_values *v, int i)
{
	v->x_ray = data->x_dir - data->x_plane + (i * 2 * data->x_plane / WIN_X);
	v->y_ray = data->y_dir - data->y_plane + (i * 2 * data->y_plane / WIN_X);
	v->delta_dist_x = 1e30;
	if (v->x_ray != 0)
		v->delta_dist_x = sqrt(1 + ((v->y_ray / v->x_ray) * (v->y_ray * v->x_ray)));
	v->delta_dist_y = 1e30;
	if (v->y_ray != 0)
		v->delta_dist_y = sqrt(1 + ((v->x_ray / v->y_ray) * (v->x_ray * v->y_ray)));
	v->hit = 0;
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
		i++;
	}
}
