/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:12:32 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/09 22:00:36 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_parsing(t_data *data)
{
	ft_init_image_struct(data);
	if (!ft_parse_input_file(data))
		return (0);
	if (!ft_fill_map_array(data))
		return (0);
	if (!ft_verif_map(data))
		return (0);
	ft_debug_map(data);
	return (1);
}







void	ft_init_image_struct(t_data *data)
{
	data->screen = (t_img){0};
	data->n_wall = (t_img){0};
	data->w_wall = (t_img){0};
	data->e_wall = (t_img){0};
	data->s_wall = (t_img){0};
	data->c_color = -1;
	data->f_color = -1;
}
