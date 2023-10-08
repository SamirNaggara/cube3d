/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:22:42 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/08 16:22:59 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	ft_debug_parsing(t_data *data)
{
	t_point	*browse;

	browse = data->map_first;
	while (browse)
	{
		ft_printf("Addrs : %p, x : %d, y : %d, type : %c, gauche : %p, droite %p, haut %p, bas %p\n", browse,
				browse->x, browse->y, browse->type, browse->lf,
				browse->rg, browse->up, browse->dw);
		browse = browse->next;
	}
}

int	ft_add_horizontal(t_data *data)
{
	t_point	*browse;

	browse = data->map_first;
	browse->lf = NULL;
	while (browse)
	{
		if (browse->next && browse->next->y != 0)
		{
			browse->rg = browse->next;
			browse->next->lf = browse;
		}
		else if (browse->next && browse->next->y == 0)
		{
			browse->rg = NULL;
			browse->next->lf = NULL;
		}
		else
			browse->rg = NULL;
		browse = browse->next;
	}
	return (1);
}

int	ft_add_vertical(t_data *data)
{
	t_point	*browse;
	t_point	*down;

	browse = data->map_first;
	while (browse)
	{
		if (browse->x == 0)
			browse->up = NULL;
		down = ft_found_down(browse);
		if (down)
		{
			browse->dw = down;
			down->up = browse;
		}
		else
			browse->dw = NULL;
		browse = browse->next;
	}
	return (1);
}

t_point	*ft_found_down(t_point *point)
{
	t_point	*browse;

	browse = point;
	while (browse)
	{
		if (point->y == browse->y && point->x + 1 == browse->x)
			return (browse);
		browse = browse->next;
	}
	return (NULL);
}

int	ft_add_line_in_list(t_data *data, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!ft_add_point(data, line[i]))
			return (0);
		data->map_end->x = data->nb_l;
		data->map_end->y = i;
		i++;
	}
	return (1);
}

int	ft_add_point(t_data *data, char type)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (!point)
		return (0);
	point->type = type;
	point->next = NULL;
	if (!data->map_first)
	{
		point->x = 0;
		point->y = 0;
		data->map_first = point;
		data->map_end = point;
		return (1);
	}
	data->map_end->next = point;
	data->map_end = point;
	return (1);
}
