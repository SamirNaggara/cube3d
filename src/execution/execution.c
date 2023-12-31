/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:28:59 by mbenicho          #+#    #+#             */
/*   Updated: 2023/10/16 15:29:02 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_loop(t_data *data)
{
	if ((data->key.w || data->key.forward)
		&& !(data->key.s || data->key.back))
		ft_move(data, data->x_dir, data->y_dir, 1);
	else if ((data->key.s || data->key.back)
		&& !(data->key.w || data->key.forward))
		ft_move(data, data->x_dir, data->y_dir, -1);
	if (data->key.a && !data->key.d)
		ft_move(data, data->x_plane, data->y_plane, -1);
	else if (data->key.d && !data->key.a)
		ft_move(data, data->x_plane, data->y_plane, 1);
	if (data->key.right && !data->key.left)
		ft_rotate(data, ROT, 1);
	else if (data->key.left && !data->key.right)
		ft_rotate(data, ROT, -1);
	ft_raycasting(data);
	return (0);
}

int	ft_init_mlx(t_data *data)
{
	data->window = mlx_new_window(data->mlx, WIN_X, WIN_Y, W_TITLE);
	if (!data->window)
		return (printf(E_WINDOW), 1);
	data->screen.img_ptr = mlx_new_image(data->mlx, WIN_X, WIN_Y);
	if (!data->screen.img_ptr)
		return (printf(E_MLX_IMG), 1);
	data->screen.address = mlx_get_data_addr(data->screen.img_ptr, \
	&data->screen.bpp, &data->screen.size_line, &data->screen.endian);
	return (0);
}

int	ft_exec(t_data *data)
{
	if (ft_init_mlx(data))
		return (data->exit_code = 1, 1);
	ft_init_dir(data);
	ft_raycasting(data);
	mlx_hook(data->window, 2, 1L << 0, ft_key_press, data);
	mlx_hook(data->window, 3, 1L << 1, ft_key_release, data);
	mlx_hook(data->window, 17, 0L, ft_exit_program, data);
	mlx_loop_hook(data->mlx, &ft_loop, data);
	mlx_loop(data->mlx);
	return (data->exit_code = 1, 1);
}
