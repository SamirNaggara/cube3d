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

#ifndef CUBE3D_H
# define CUBE3D_H

# define WINDOW_X_SIZE 1920
# define WINDOW_Y_SIZE 1080
# define W_TITLE "Cube 3D en béton armée !\n"

# include <stdlib.h>
# include "libft-plus/libft/libft.h"
# include "libft-plus/printf/ft_printf.h"
# include "libft-plus/get-next-line/get_next_line.h"
# include "minilibx/mlx.h"
# include <math.h>
# include <stdarg.h>
# include <string.h>
# include <signal.h>


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
    double	x_player;
    double	y_player;
    char	dir;
    t_img	*n_wall;
    t_img	*o_wall;
    t_img	*w_wall;
    t_img	*s_wall;
    int		c_color;
    int		f_color;
	int		ac;
	char	**av;



}    t_data;


/* PARSING */
int	ft_parsing(t_data *data);

/* EXECUTION */
int	ft_exec(t_data *data);
int	ft_init_mlx(t_data *data);
int	ft_destroy_mlx(t_data *data);
int	ft_load_images(t_data *data);

#endif