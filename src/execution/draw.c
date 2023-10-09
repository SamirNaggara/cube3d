#include "../../cube3d.h"

void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_X && y >= 0 && y < WIN_Y)
	{
		dst = img->address + (y * img->size_line + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	ft_draw_vertical_line(t_img *img, int x, int start, int end, int color)
{
	int	y;

	y = start;
	while (y < end)
	{
		ft_pixel_put(img, x, y, color);
		y++;
	}
	return (y);
}

void	ft_draw_texture(t_data *data, t_values *v, int x)
{
	t_img	*tex;
	double	wall_x;
	int		y;
	int		color;

	tex = NULL;
	if (v->side == 1 && v->y_ray <= 0)
		tex = &data->s_wall;
	else if (v->side == 1 && v->y_ray > 0)
		tex = &data->n_wall;
	else if (v->side == 0 && v->x_ray <= 0)
		tex = &data->e_wall;
	else if (v->side == 0 && v->x_ray > 0)
		tex = &data->w_wall;
	if (v->side == 1)
		wall_x = data->x_player + v->wall_dist * v->x_ray;
	else
		wall_x = data->y_player + v->wall_dist * v->y_ray;
	wall_x -= (int)wall_x;
	y = 0;
	while (y + v->start < v->end)
	{
		color = *(unsigned int *)(tex->address + ((y * tex->height / v->height) \
		* tex->size_line + (int)(wall_x * (double)tex->width) * (tex->bpp / 8)));
		ft_pixel_put(&data->screen, x, y + v->start, color);
		y++;
	}
}

void	ft_draw(t_data *data, t_values *v, int x)
{
	int	diff;

	diff = 0;
	if (data->key.ctrl && !data->key.shift)
		diff = WIN_Y / 12;
	v->height = WIN_Y / v->wall_dist;
	v->start = (WIN_Y / 2) - (v->height / 2) - diff;
	v->end = (WIN_Y / 2) + (v->height / 2) - diff;
	ft_draw_vertical_line(&data->screen, x, 0, v->start, data->c_color);
	ft_draw_texture(data, v, x);
	ft_draw_vertical_line(&data->screen, x, v->end, WIN_Y, data->f_color);
}
