/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:06:36 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/09 19:34:23 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	ft_load_images(t_data *data)
{
	if (!ft_create_image(data, &data->n_wall, data->n_wall.path))
		return (0);
	if (!ft_create_image(data, &data->e_wall, data->e_wall.path))
		return (0);
	if (!ft_create_image(data, &data->s_wall, data->s_wall.path))
		return (0);
	if (!ft_create_image(data, &data->w_wall, data->w_wall.path))
		return (0);
	return (1);
}

int	ft_create_image(t_data *data, t_img *img, char *path)
{
	img->img_ptr = mlx_xpm_file_to_image
		(data->mlx, path, &img->width, &img->height);
	if (!img->img_ptr)
		return (0);
	img->address = mlx_get_data_addr
		(img->img_ptr, &img->bpp, &img->size_line, &img->endian);
	if (!img->address)
		return (0);
	return (1);
}
