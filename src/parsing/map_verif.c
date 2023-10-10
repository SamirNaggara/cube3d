/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verif.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:58:47 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/10 17:01:48 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_verif_map(t_data *data)
{
	if (!ft_authorize_char(data))
		return (ft_printf(E_CHAR), 0);
	if (!ft_one_player(data))
		return (ft_printf(E_PLAYER), 0);
	if (!ft_map_open(data))
		return (ft_printf(E_MAP_OPEN), 0);
	return (1);
}

int	ft_one_player(t_data *data)
{
	t_point	*point;
	int		nb_player;

	nb_player = 0;
	point = data->map_first;
	while (point)
	{
		if (ft_char_in_array(point->type, DIR))
		{
			ft_fill_player_data(data, point);
			nb_player++;
		}
		point = point->next;
	}
	if (nb_player != 1)
		return (0);
	return (1);
}

void	ft_fill_player_data(t_data *data, t_point *point)
{
	data->x_player = point->y + 0.5;
	data->y_player = point->x - 0.5;
	data->dir = point->type;
}
