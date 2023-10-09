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
	double	speed;

	speed = MOVE;
	if (data->key.shift && !data->key.ctrl)
		speed *= 2;
	else if (data->key.ctrl && !data->key.shift)
		speed *= 0.4;
	if (data->map[(int)data->y_player][(int)(data->x_player + (x_dir * speed * side))] != '1')
		data->x_player += x_dir * speed * side;
	if (data->map[(int)((data->y_player + y_dir * speed * side))][(int)data->x_player] != '1')
		data->y_player += y_dir * speed * side;
}
