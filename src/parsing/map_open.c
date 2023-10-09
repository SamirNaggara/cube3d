/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 22:00:10 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/09 22:00:53 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_map_open(t_data *data)
{
	t_point	*point;

	point = data->map_first;
	while (point)
	{
		if (point->type != '1' && point->type != ' ')
		{
			if (!ft_tile_available(point->rg))
				return (0);
			if (!ft_tile_available(point->lf))
				return (0);
			if (!ft_tile_available(point->up))
				return (0);
			if (!ft_tile_available(point->dw))
				return (0);
		}
		point = point->next;
	}
	return (1);
}

int	ft_tile_available(t_point *point)
{
	if (!point)
		return (0);
	if (point->type == ' ')
		return (0);
	return (1);
}

int	ft_authorize_char(t_data *data)
{
	t_point	*point;

	point = data->map_first;
	while (point)
	{
		if (!ft_char_in_array(point->type, AUTH_CHAR))
			return (0);
		point = point->next;
	}
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
			nb_player++;
		point = point->next;
	}
	if (nb_player != 1)
		return (0);
	return (1);
}
