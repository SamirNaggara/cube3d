/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenicho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:29:29 by mbenicho          #+#    #+#             */
/*   Updated: 2023/10/16 15:29:31 by mbenicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_X && y >= 0 && y < WIN_Y)
	{
		dst = img->address + (y * img->size_line + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	ft_draw_vertical_line(t_data *data, int x, int start, int end)
{
	int	y;
	int	color;

	if (start == 0)
		color = data->c_color;
	else
		color = data->f_color;
	y = start;
	while (y < end)
	{
		ft_pixel_put(&data->screen, x, y, color);
		y++;
	}
	return (y);
}

t_img	*ft_find_tex(t_data *data, t_values *v)
{	
	if (v->side == 1 && v->y_ray <= 0)
		return (&data->s_wall);
	else if (v->side == 1 && v->y_ray > 0)
		return (&data->n_wall);
	else if (v->side == 0 && v->x_ray <= 0)
		return (&data->e_wall);
	else
		return (&data->w_wall);
}

void	ft_draw_texture(t_data *data, t_values *v, int x)
{
	t_img	*tex;
	double	wall_x;
	int		y;
	int		color;

	tex = ft_find_tex(data, v);
	if (v->side == 1)
		wall_x = data->x_player + v->wall_dist * v->x_ray;
	else
		wall_x = data->y_player + v->wall_dist * v->y_ray;
	wall_x -= (int)wall_x;
	if ((v->side == 1 && v->y_ray > 0) || (v->side == 0 && v->x_ray <= 0))
		wall_x = 1 - wall_x;
	y = 0;
	while (y + v->start < v->end)
	{
		color = *(unsigned int *)(tex->address \
		+ ((y * tex->height / v->height) * tex->size_line \
		+ (int)(wall_x * (double)tex->width) *(tex->bpp / 8)));
		ft_pixel_put(&data->screen, x, y + v->start, color);
		y++;
	}
}

void	ft_draw(t_data *data, t_values *v, int x)
{
	int	diff;

	diff = 0;
	if (data->key.ctrl && !(data->key.shift || data->key.space))
		diff = WIN_Y / 12;
	v->height = WIN_Y / v->wall_dist;
	v->start = (WIN_Y / 2) - (v->height / 2) - diff;
	v->end = (WIN_Y / 2) + (v->height / 2) - diff;
	ft_draw_vertical_line(data, x, 0, v->start);
	ft_draw_texture(data, v, x);
	ft_draw_vertical_line(data, x, v->end, WIN_Y);
}
