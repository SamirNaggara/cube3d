/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:35:04 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/16 15:30:33 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	main(int ac, char **av)
{
	t_data	data;

	data = (t_data){0};
	data.ac = ac;
	data.av = av;
	data.mlx = mlx_init();
	if (!data.mlx)
		return (printf(E_MLX), 1);
	if (!ft_parsing(&data))
		return (ft_exit_program(&data), 1);
	if (!ft_load_images(&data))
		return (ft_printf(E_IMG), 1);
	ft_exec(&data);
	printf("Unexpected error\n");
	return (ft_exit_program(&data), 1);
}
