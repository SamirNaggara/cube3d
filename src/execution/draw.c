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

void	ft_draw(t_data *data, t_values *v, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = WIN_Y / v->wall_dist;
	draw_start = (WIN_Y / 2) - (line_height / 2);
	draw_end = (WIN_Y / 2) + (line_height / 2);
	ft_draw_vertical_line(&data->screen, x, 0, draw_start, data->c_color);
	ft_draw_vertical_line(&data->screen, x, draw_start, draw_end, 0x555555);
	ft_draw_vertical_line(&data->screen, x, draw_end, WIN_Y, data->f_color);
}
