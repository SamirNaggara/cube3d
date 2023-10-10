/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:12:09 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/10 14:09:26 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

/*
	Open the map
	Then read each line
	And stock it parsing struct
*/
int	ft_parse_input_file(t_data *data)
{
	int		fd;

	if (!ft_verify_cub(data->av[1]))
		return (ft_printf(E_EXT), 0);
	fd = open(data->av[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf(E_OPEN_FILE), 0);
	if (!ft_read_data(data, fd))
		return (0);
	if (!ft_read_map(data, fd))
		return (ft_printf(E_MAP), 0);
	close(fd);
	ft_add_horizontal(data);
	ft_add_vertical(data);
	return (1);
}

int	ft_verify_cub(char *name)
{
	int	i;

	i = ft_strlen(name);
	if (name[i - 1] != 'b')
		return (0);
	if (name[i - 2] != 'u')
		return (0);
	if (name[i - 3] != 'c')
		return (0);
	if (name[i - 4] != '.')
		return (0);
	return (1);
}
