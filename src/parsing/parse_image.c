/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:12:01 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/09 19:33:28 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_read_image_input(t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	while (line)
	{
		if (!ft_insert_wall_path(data, line))
			return (free(line), 0);
		free(line);
		if (ft_wall_paths_exist(data))
			break ;
		line = get_next_line(fd);
		if (!line)
			return (close(fd), 0);
	}
	return (1);
}

int	ft_insert_wall_path(t_data *data, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		data->n_wall.path = ft_strdup_without_nl(line + 3);
		if (!data->n_wall.path)
			return (0);
	}
	if (ft_strncmp(line, "SO ", 3) == 0)
	{
		data->s_wall.path = ft_strdup_without_nl(line + 3);
		if (!data->s_wall.path)
			return (0);
	}
	if (ft_strncmp(line, "WE ", 3) == 0)
	{
		data->w_wall.path = ft_strdup_without_nl(line + 3);
		if (!data->w_wall.path)
			return (0);
	}
	if (!ft_cmp_last_wall(data, line))
		return (0);
	return (1);
}

int	ft_cmp_last_wall(t_data *data, char *line)
{
	if (ft_strncmp(line, "EA ", 3) == 0)
	{
		data->e_wall.path = ft_strdup_without_nl(line + 3);
		if (!data->e_wall.path)
			return (0);
	}
	return (1);
}

char	*ft_strdup_without_nl(char *s)
{
	char	*result;
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	ft_memset(result, 0, size + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		result[i] = s[i];
		i++;
	}
	return (result);
}

int	ft_wall_paths_exist(t_data *data)
{
	if (!data->n_wall.path)
		return (0);
	else if (!data->s_wall.path)
		return (0);
	else if (!data->w_wall.path)
		return (0);
	else if (!data->e_wall.path)
		return (0);
	return (1);
}
