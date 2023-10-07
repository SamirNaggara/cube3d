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
		return (0);
	if (!ft_init_mlx(&data))
		return (0);  //free a ajouter
	if (!ft_load_images(&data))
		return (0);  //free a ajouter
	if (!ft_exec(&data))
		return (0);  //free a ajouter
	ft_destroy_mlx(&data);
	return (0);

}

int	ft_init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->window = mlx_new_window(data->mlx, WINDOW_X_SIZE,
			WINDOW_Y_SIZE, W_TITLE);
	if (!data->window)
		return (mlx_destroy_display(data->mlx), 0);
	return (1);
}

int	ft_destroy_mlx(t_data *data)
{
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	return (1);
}
