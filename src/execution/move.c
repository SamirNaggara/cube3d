#include "../../cube3d.h"

void	ft_rotate(t_data *data, int side)
{
	double	tmp;
	double	rot;

	rot = ROT * side;
	tmp = data->x_dir;
	data->x_dir = data->x_dir * cos(rot) - data->y_dir * sin(rot);
	data->y_dir = tmp * sin(rot) + data->y_dir * cos(rot);
	tmp = data->x_plane;
	data->x_plane = data->x_plane * cos(rot) - data->y_plane * sin(rot);
	data->y_plane = tmp * sin(rot) + data->y_plane * cos(rot);
}

void	ft_move(t_data *data, double x_dir, double y_dir, int side)
{
	if (data->map[(int)data->y_player][(int)(data->x_player + (x_dir * MOVE * side))] != '1')
		data->x_player += x_dir * MOVE * side;
	if (data->map[(int)((data->y_player + y_dir * MOVE * side))][(int)data->x_player] != '1')
		data->y_player += y_dir * MOVE * side;
}
