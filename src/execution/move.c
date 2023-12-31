/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:29:22 by mbenicho          #+#    #+#             */
/*   Updated: 2023/10/16 15:29:23 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_rotate(t_data *data, double rot, int side)
{
	double	tmp;

	rot *= side;
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
	if (side == 1 && x_dir == data->x_dir && y_dir == data->y_dir \
	&& (data->key.shift || data->key.space) && !data->key.ctrl)
		speed *= 2;
	else if (data->key.ctrl && !(data->key.shift || data->key.space))
		speed *= 0.4;
	if (data->map[(int)data->y_player] \
	[(int)(data->x_player + (x_dir * COLLISION * side))] != '1')
		data->x_player += x_dir * speed * side;
	if (data->map[(int)((data->y_player + y_dir * COLLISION * side))] \
	[(int)data->x_player] != '1')
		data->y_player += y_dir * speed * side;
}
