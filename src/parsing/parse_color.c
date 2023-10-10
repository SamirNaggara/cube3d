/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:11:51 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/10 17:03:33 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_get_colors_input(t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	while (line)
	{
		if (!ft_insert_colors(data, line))
			return (0);
		free(line);
		if (data->c_color != -1 && data->f_color != -1)
			break ;
		line = get_next_line(fd);
		if (!line)
			return (close(fd), 0);
	}
	return (1);
}

int	ft_insert_colors(t_data *data, char *line)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		data->f_color = ft_get_color_from_rgb(line + 1);
		if (data->f_color == -1)
			return (0);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		data->c_color = ft_get_color_from_rgb(line + 1);
		if (data->c_color == -1)
			return (0);
	}
	return (1);
}

int	ft_get_color_from_rgb(char *line)
{
	t_rgb	rgb;

	while (*line == ' ')
		line++;
	rgb.red = ft_extract_number(line);
	line = ft_strchr(line, ',');
	if (!line)
		return (-1);
	line++;
	rgb.green = ft_extract_number(line);
	line = ft_strchr(line, ',');
	if (!line)
		return (-1);
	line++;
	rgb.blue = ft_extract_number(line);
	if (rgb.blue == -1 || rgb.green == -1 || rgb.red == -1)
		return (-1);
	return (ft_create_rgb(rgb.red, rgb.green, rgb.blue));
}

int	ft_extract_number(char *str)
{
	int		nb;
	int		i;

	nb = 0;
	if (!str || !*str)
		return (-1);
	i = 0;
	if (!ft_isalnum(str[i]))
		return (-1);
	while (str[i] && str[i] != ',' && str[i] != '\n' && str[i] != ' ')
	{
		if (!ft_isalnum(str[i]))
			return (0);
		nb = nb * 10 + str[i] - '0';
		if (nb > 255)
			return (-1);
		i++;
	}
	if (nb < 0 || nb > 255)
		return (-1);
	return (nb);
}

int	ft_create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
