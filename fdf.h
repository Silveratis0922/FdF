/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:11:30 by tchantro          #+#    #+#             */
/*   Updated: 2022/10/10 16:10:39 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <strings.h>
# include <bsd/string.h>
# include <ctype.h>
# include <stdarg.h>
# include <math.h>
# include "libft.h"
# include "./mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# define WIN_X 2520
# define WIN_Y 1080
# define SPACE 24
# define Z	30
# define PURPLE 0xff00ff

typedef struct s_draw
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	float	dx;
	float	dy;
	float	step;
}	t_draw;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_size
{
	int	x;
	int	y;
	int	columns;
	int	line;
	int	color;
}	t_size;

typedef struct s_img
{
	void	*mlx_img;
	char	*adrs;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		**map_x;
	int		**map_y;
	int		**map_z;
	t_img	img;
	t_size	size;
	t_draw	draw;
	t_point	point;
}	t_data;

int		main(int argc, char **argv);
int		verif_arg(char *str, char *verif);
int		**read_file(char *arg, t_data *data);
int		initialize(t_data *data);
int		test(t_data *data);
void	img_pix_put(t_img *img, int x, int y, int color);
void	mapping_iso_coor(t_data *data);
int		**init_map_x(t_data *data);
int		**init_map_y(t_data *data);
void	coor_x(t_data *data, int pos_x, int x, int y);
void	coor_y(t_data *data, int pos_y, int x, int y);
void	line_drawing(t_data *data, int x, int y, char c);
void	printing_pixel_horizontal(t_data *data);
void	printing_pixel_vertical(t_data *data);
void	background(t_img *img, int color);
void	center_of_window(t_data *data, int color);
void	destroy_malloc(t_data *data);

#endif
