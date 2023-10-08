/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:20:33 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/08 16:22:52 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_fill_map_array(t_data *data)
{
	t_point	*point;
	int		i;

	if (!data->map_first)
		return (0);
	data->map = (char **)malloc(sizeof(char *) * (data->nb_l + 1));
	if (!data->map)
		return (0);
	point = data->map_first;
	i = 0;
	while (point)
	{
		if (!ft_fill_map_line(data, i++, &point))
			return (0);
	}
	data->map[i] = NULL;
	return (1);
}

int	ft_fill_map_line(t_data *data, int i, t_point **point)
{
	int	j;
	
	data->map[i] = (char *)malloc(sizeof(char) * (data->ll  + 1));
	if (!data->map[i])
		return (0);
	ft_memset(data->map[i], ' ', data->ll);
	data->map[i][data->ll] = '\0';
	j = 0;
	while ((*point)->rg)
	{
		data->map[i][j++] = (*point)->type;
		*point = (*point)->rg;
	}
	data->map[i][j] = (*point)->type;
	*point = (*point)->next;
	return (1);
}

void	ft_debug_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("Map de %d lignes et %d colonnes \n\n", data->nb_l, data->ll);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
			ft_printf("%c", data->map[i][j++]);
		ft_printf("\n");
		i++;
	}
}
