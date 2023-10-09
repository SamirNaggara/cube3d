/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:35:04 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/09 21:51:05 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	data = (t_data){0}; //init toute la structure a 0
	data.ac = ac;
	data.av = av;
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	if (!ft_parsing(&data))
		return (ft_exit_program(&data), 1);
	if (!ft_load_images(&data))
		return (ft_printf(E_IMG), 1);  //free a ajouter
	//ft_exec(&data);
	return (ft_exit_program(&data), 1);
}
