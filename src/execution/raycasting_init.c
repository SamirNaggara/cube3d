/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:28:30 by mbenicho          #+#    #+#             */
/*   Updated: 2023/10/16 15:28:32 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_init_dir(t_data *data)
{
	if (data->dir == 'N')
		data->y_dir = -1;
	else if (data->dir == 'S')
		data->y_dir = 1;
	else if (data->dir == 'W')
		data->x_dir = -1;
	else if (data->dir == 'E')
		data->x_dir = 1;
	if (data->x_dir != 0)
		data->y_plane = 0.66;
	else
		data->x_plane = 0.66;
	if (data->x_dir > 0 || data->y_dir > 0)
	{
		data->x_plane *= -1;
		data->y_plane *= -1;
	}
}

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

double	ft_abs(double value)
{
	if (value < 0)
		return (value * -1);
	return (value);
}

void	ft_init_values(t_data *data, t_values *v, int x)
{
	v->map_x = (int)data->x_player;
	v->map_y = (int)data->y_player;
	v->x_ray = data->x_dir - data->x_plane + (x * 2 * data->x_plane / WIN_X);
	v->y_ray = data->y_dir - data->y_plane + (x * 2 * data->y_plane / WIN_X);
	v->delta_dist_x = 1e30;
	if (v->x_ray != 0)
		v->delta_dist_x = ft_abs(1 / v->x_ray);
	v->delta_dist_y = 1e30;
	if (v->y_ray != 0)
		v->delta_dist_y = ft_abs(1 / v->y_ray);
	ft_init_step(data, v);
	v->hit = 0;
}
