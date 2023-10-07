/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snaggara <snaggara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:34:58 by snaggara          #+#    #+#             */
/*   Updated: 2023/10/07 17:13:57 by snaggara         ###   ########.fr       */
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

typedef struct	s_data
{
	void	*mlx;
	void	*window;
    char	**map;
	t_key	key;
    double	x_player;
    double	y_player;
	double	x_dir;
	double	y_dir;
	double	x_plane;
	double	y_plane;
    char	dir;
	t_img	screen;
    t_img	n_wall;
    t_img	w_wall;
    t_img	e_wall;
    t_img	s_wall;
    int		c_color;
    int		f_color;
	int		ac;
	char	**av;
	int		exit_code;
}    t_data;


/* PARSING */
int	ft_parsing(t_data *data);

/* EXECUTION */
int		ft_exec(t_data *data);
int		ft_init_mlx(t_data *data);
int		ft_exit_program(t_data *data);
int		ft_key_press(int keycode, t_data *data);
int		ft_key_release(int keycode, t_data *data);
int		ft_load_images(t_data *data);

#endif
