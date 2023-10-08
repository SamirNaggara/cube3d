/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:35:04 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/07 17:18:06 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	data = (t_data){0}; //init toute la structure a 0
	data.ac = ac;
	data.av = av;
	if (!ft_parsing(&data))
		return (1);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	if (!ft_load_images(&data))
		return (1);  //free a ajouter
	ft_exec(&data);
	return (ft_exit_program(&data), 1);
}

int	ft_exit_program(t_data *data)
{
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
