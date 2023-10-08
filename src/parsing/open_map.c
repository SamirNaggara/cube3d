/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:21:37 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/08 16:21:49 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

/*
	Open the map
	Then read each line
	And stock it parsing struct
*/
int	ft_open_map(t_data *data)
{
	int		fd;
	char	*line;

	fd = open(data->av[1], O_RDONLY);
	if (!fd)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	data->nb_l++;
	data->ll = (int)ft_strlen(line) - 1;
	if (data->ll == 0)
		return (0);
	while (line)
	{
		if (!ft_add_line_in_list(data, line))
			return (0);
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		data->ll = ft_max(data->ll, (int)ft_strlen(line) - 1);
		data->nb_l++;
	}
	ft_add_horizontal(data);
	ft_add_vertical(data);
	return (1);
}
