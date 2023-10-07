#include "../../cube3d.h"

int	ft_key_press(int keycode, t_data *data)
{
	if (keycode == W)
		data->key.w = 1;
	else if (keycode == A)
		data->key.a = 1;
	else if (keycode == S)
		data->key.s = 1;
	else if (keycode == D)
		data->key.d = 1;
	else if (keycode == LEFT)
		data->key.left = 1;
	else if (keycode == RIGHT)
		data->key.right = 1;
	else if (keycode == EXIT)
		ft_exit_program(data);
	return (0);
}

int	ft_key_release(int keycode, t_data *data)
{
	if (keycode == W)
		data->key.w = 0;
	else if (keycode == A)
		data->key.a = 0;
	else if (keycode == S)
		data->key.s = 0;
	else if (keycode == D)
		data->key.d = 0;
	else if (keycode == LEFT)
		data->key.left = 0;
	else if (keycode == RIGHT)
		data->key.right = 0;
	return (0);
}