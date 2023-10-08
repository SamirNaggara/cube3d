/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:32:25 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/08 17:43:04 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_exit_program(t_data *data)
{
	ft_free_parsing(data);
	ft_free_map(data);
	if (data->n_wall.img_ptr)
		mlx_destroy_image(data->mlx, data->n_wall.img_ptr);
	if (data->w_wall.img_ptr)
		mlx_destroy_image(data->mlx, data->w_wall.img_ptr);
	if (data->e_wall.img_ptr)
		mlx_destroy_image(data->mlx, data->e_wall.img_ptr);
	if (data->s_wall.img_ptr)
		mlx_destroy_image(data->mlx, data->s_wall.img_ptr);
	if (data->screen.img_ptr)
		mlx_destroy_image(data->mlx, data->screen.img_ptr);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(data->exit_code);
	return (0);
}

void	ft_free_parsing(t_data *data)
{
	t_point	*point;
	t_point	*tmp;

	point = data->map_first;
	if (!point)
		return ;
	while (point)
	{
		tmp = point;
		point = point->next;
		free(tmp);
	}
	data->map_first = NULL;
	data->map_end = NULL;
}

void	ft_free_map(t_data *data)
{
	int	i;

	if (!data->map)
		return ;
	i = 0;
	while (data->map[i])
		free(data->map[i++]);
	free(data->map[i]);
	free(data->map);
	data->map = NULL;
}