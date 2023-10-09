/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:34:58 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/09 22:00:56 by snaggara         ###   ########.fr       */
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
# define FORWARD 65362
# define BACK 65364
# define SHIFT 65505
# define CTRL 65507

# define DIR "NSWE"
# define AUTH_CHAR "NSWE01 "

# define E_MAP "Error\nMap is empty or was not properly open\n"
# define E_WALL_PARSE "Error\nProblem with the parsing of the walls images\n"
# define E_COLORS_PARSE "Error\nProblem with the parsing of the colors\n"
# define E_EMPTY_LINE "Empty line in map\n"
# define E_IMG "An error occur while loading an image\n"
# define E_PLAYER "Error\nThe map need exactly one player\n"
# define E_CHAR "Error\nAn not authorize charactere is in the map\n"
# define E_MAP_OPEN "Error\nThe map shoudn't be as open as your gf\n"

# define ROT 0.014
# define MOVE 0.04

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
	int	forward;
	int	back;
	int	shift;
	int	ctrl;
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
	char	*path;
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
	int		height;
	int		start;
	int		end;
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

typedef struct	s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;


/* PARSING */
int		ft_parsing(t_data *data);
int		ft_parse_input_file(t_data *data);
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
int		ft_read_image_input(t_data *data, int fd);
int		ft_insert_wall_path(t_data *data, char *line);
int		ft_wall_paths_exist(t_data *data);
void	ft_init_image_struct(t_data *data);
int		ft_get_colors_input(t_data *data, int fd);
int		ft_insert_colors(t_data *data, char *line);
int		ft_get_color_from_rgb(char *line);
int		ft_extract_number(char *str);
int		ft_create_rgb(int r, int g, int b);
int		ft_read_map(t_data *data, int fd);
char	*ft_read_while_space(int fd);
int		ft_cmp_last_wall(t_data *data, char *line);
char	*ft_strdup_without_nl(char *s);
int		ft_verif_map(t_data *data);
int		ft_one_player(t_data *data);
int		ft_char_in_array(char c, char *str);
int		ft_authorize_char(t_data *data);
int		ft_map_open(t_data *data);

int		ft_tile_available(t_point *point);

/* EXECUTION */
int		ft_exec(t_data *data);
int		ft_init_mlx(t_data *data);
void	ft_init_dir(t_data *data);
void	ft_raycasting(t_data *data);
void	ft_init_step(t_data *data, t_values *v);
void	ft_init_values(t_data *data, t_values *v, int x);
void	ft_algorithm(t_data *d, t_values *v);
void	ft_pixel_put(t_img *img, int x, int y, int color);
void	ft_draw(t_data *data, t_values *v, int x);
int		ft_draw_vertical_line(t_img *img, int x, int start, int end, int color);
void	ft_rotate(t_data *data, int side);
void	ft_move(t_data *data, double x_dir, double y_dir, int side);
int		ft_exit_program(t_data *data);
int		ft_key_press(int keycode, t_data *data);
int		ft_key_release(int keycode, t_data *data);
int		ft_load_images(t_data *data);

/* LOAD IMAGE */
int	ft_load_images(t_data *data);
int	ft_create_image(t_data *data, t_img *img);

/* FREE */
void	ft_free_parsing(t_data *data);
void	ft_free_map(t_data *data);
void	ft_free_img_path(t_data *data);

#endif
