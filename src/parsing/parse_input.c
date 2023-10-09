/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:12:09 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/09 16:12:11 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

/*
	Open the map
	Then read each line
	And stock it parsing struct
*/
int	ft_parse_input_file(t_data *data)
{
	int		fd;

	fd = open(data->av[1], O_RDONLY);
	if (!fd)
		return (0);
	if (!ft_read_image_input(data, fd))
		return (ft_printf(E_WALL_PARSE), 0);
	if (!ft_get_colors_input(data, fd))
		return (ft_printf(E_COLORS_PARSE), 0);
	if (!ft_read_map(data, fd))
		return (ft_printf(E_MAP), 0);
	close(fd);
	ft_add_horizontal(data);
	ft_add_vertical(data);
	return (1);
}

