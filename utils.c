/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 14:53:23 by tchantro          #+#    #+#             */
/*   Updated: 2022/10/10 12:18:20 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->adrs + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	line_drawing(t_data *data, int x, int y, char c)
{
	float	i;
	float	j;
	int		print;

	data->draw.x1 = data->map_x[y][x];
	data->draw.y1 = data->map_y[y][x];
	if (c == 'H')
		x = x + 1;
	else
		y = y + 1;
	data->draw.x2 = data->map_x[y][x];
	data->draw.y2 = data->map_y[y][x];
	data->draw.dx = data->draw.x2 - data->draw.x1;
	data->draw.dy = data->draw.y2 - data->draw.y1;
	if (abs(data->draw.dx) >= abs(data->draw.dy))
		data->draw.step = abs(data->draw.dx);
	else
		data->draw.step = abs(data->draw.dy);
	print = 0;
	i = data->draw.y1;
	j = data->draw.x1;
	while (print++ < data->draw.step)
	{
		j = j + data->draw.dx / data->draw.step;
		i = i + data->draw.dy / data->draw.step;
		img_pix_put(&data->img, roundf(j), roundf(i), PURPLE);
	}
}

void	printing_pixel_horizontal(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	img_pix_put(&data->img, data->map_x[0][0], data->map_y[0][0], PURPLE);
	while (y < data->size.y)
	{
		x = 0;
		while (x < data->size.x - 1)
		{
			line_drawing(data, x, y, 'H');
			x++;
		}
		y++;
	}
}

void	printing_pixel_vertical(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->size.y - 1)
	{
		x = 0;
		while (x < data->size.x)
		{
			line_drawing(data, x, y, 'V');
			x++;
		}
		y++;
	}
}

void	background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_Y)
	{
		j = 0;
		while (j < WIN_X)
			img_pix_put(img, j++, i, color);
		i++;
	}
}

void	center_of_window(t_data *data, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_Y)
	{
		x = 0;
		while (x < WIN_X)
		{
			if (x == WIN_X / 2)
				img_pix_put(&data->img, x, y, color);
			else if (y == WIN_Y / 2)
				img_pix_put(&data->img, x, y, color);
			x++;
		}
		y++;
	}
}
