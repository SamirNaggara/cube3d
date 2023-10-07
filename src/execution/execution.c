/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:00:35 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/07 17:12:33 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_loop(t_data *data)
{
	(void)data;
	return (0);
}

int	ft_init_mlx(t_data *data)
{
	data->window = mlx_new_window(data->mlx, WIN_X, WIN_Y, W_TITLE);
	if (!data->window)
		return (1);
	data->screen.img_ptr = mlx_new_image(data->mlx, WIN_X, WIN_Y);
	if (!data->screen.img_ptr)
		return (1);
	data->screen.address = mlx_get_data_addr(data->screen.img_ptr, \
	&data->screen.bpp, &data->screen.size_line, &data->screen.endian);
	return (0);
}

int	ft_exec(t_data *data)
{
	if (ft_init_mlx(data))
		return (data->exit_code = 1, ft_exit_program(data), 1);
	mlx_hook(data->window, 2, 1L << 0, ft_key_press, data);
	mlx_hook(data->window, 3, 1L << 1, ft_key_release, data);
	mlx_hook(data->window, 17, 0L, ft_exit_program, data);
	mlx_loop_hook(data->mlx, &ft_loop, data);
	mlx_loop(data->mlx);
	return (data->exit_code = 1, 1);
}
