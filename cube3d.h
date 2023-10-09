/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:34:58 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/08 17:38:40 by snaggara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIN_X 1920
# define WIN_Y 1080
# define W_TITLE "Cube 3D en beton arme !\n"

# define EXIT 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

# define E_MAP "Error\nMap is empty or was not properly open\n"


# include <stdlib.h>
# include "libft-plus/libft/libft.h"
# include "libft-plus/printf/ft_printf.h"
# include "libft-plus/get-next-line/get_next_line.h"
# include "minilibx/mlx.h"
# include <math.h>
# include <stdarg.h>
# include <string.h>
# include <signal.h>

typedef struct s_key
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_key;

typedef struct	s_img
{
	char	*address;
	void	*img_ptr;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_point {
	int				x;
	int				y;
	char			type;
	struct s_point	*up;
	struct s_point	*dw;
	struct s_point	*lf;
	struct s_point	*rg;
	struct s_point	*next;
	int				tmp;
}	t_point;

typedef struct	s_values
{
	double	x_ray;			//ray coordinates
	double	y_ray;
	double	delta_dist_x;	//distance between to x walls
	double	delta_dist_y;
	double	side_dist_x;	//distance between player and next x wall
	double	side_dist_y;
	double	wall_dist;		//distance traveled by the ray until it hits a wall
	int		map_x;			//coordinates of the tile the player is in
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;			//set to 1 when the ray hits a wall
	int		side;			//to determine which side of the wall was hit
}	t_values;

typedef struct	s_data
{
	void		*mlx;
	void		*window;
    char		**map;
	t_key		key;
    double		x_player;
    double		y_player;
	double		x_dir;
	double		y_dir;
	double		x_plane;
	double		y_plane;
    char		dir;
	t_img		screen;
    t_img		n_wall;
    t_img		w_wall;
    t_img		e_wall;
    t_img		s_wall;
    int			c_color;
    int			f_color;
	int			ac;
	char		**av;
	int			exit_code;
	t_point		*map_first;
	t_point		*map_end;
	int			nb_l;
	int			ll;
}    t_data;

/* PARSING */
int		ft_parsing(t_data *data);
int		ft_open_map(t_data *data);
void	ft_debug_parsing(t_data *data);
int		ft_add_horizontal(t_data *data);
int		ft_add_vertical(t_data *data);
t_point	*ft_found_down(t_point *point);
int		ft_add_line_in_list(t_data *data, char *line);
int		ft_add_point(t_data *data, char type);
int		ft_fill_map_array(t_data *data);
int		ft_max(int nb1, int nb2);
void	ft_debug_map(t_data *data);
int		ft_fill_map_line(t_data *data, int i, t_point **point);

/* EXECUTION */
int		ft_exec(t_data *data);
int		ft_init_mlx(t_data *data);
void	ft_raycasting(t_data *data);
void	ft_init_step(t_data *data, t_values *v);
void	ft_init_values(t_data *data, t_values *v, int x);
void	ft_algorithm(t_data *d, t_values *v);
void	ft_pixel_put(t_img *img, int x, int y, int color);
void	ft_draw(t_data *data, t_values *v, int x);
int		ft_exit_program(t_data *data);
int		ft_key_press(int keycode, t_data *data);
int		ft_key_release(int keycode, t_data *data);
int		ft_load_images(t_data *data);

/* FREE */
void	ft_free_parsing(t_data *data);
void	ft_free_map(t_data *data);

#endif
