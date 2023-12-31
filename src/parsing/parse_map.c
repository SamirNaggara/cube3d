/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:12:18 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/10 14:06:33 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_read_map(t_data *data, int fd)
{
	char	*line;

	line = ft_read_while_space(fd);
	if (!line)
		return (0);
	data->nb_l++;
	data->ll = (int)ft_strlen(line) - 1;
	while (line)
	{
		if (!ft_add_line_in_list(data, line))
			return (free(line), 0);
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		data->ll = ft_max(data->ll, (int)ft_strlen(line) - 1);
		data->nb_l++;
	}
	return (free(line), 1);
}

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

	data->map[i] = (char *)malloc(sizeof(char) * (data->ll + 1));
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

char	*ft_read_while_space(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && *line == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (close(fd), NULL);
	return (line);
}
