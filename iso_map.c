/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:12:34 by tchantro          #+#    #+#             */
/*   Updated: 2022/10/10 12:07:56 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	coor_x(t_data *data, int pos_x, int x, int y)
{
	data->map_x[y][x] = pos_x;
}

void	coor_y(t_data *data, int pos_y, int x, int y)
{
	data->map_y[y][x] = pos_y;
}

void	mapping_iso_coor(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y != data->size.y)
	{
		x = 0;
		while (x != data->size.x)
		{
			coor_x(data, cos(M_PI / 6) * (x - y) * SPACE + WIN_X / 2, x, y);
			coor_y(data, sin(M_PI / 6) * (x + y) * SPACE + WIN_Y / 2 - Z * data->map_z[y][x] - ((data->size.y - 1) * SPACE / 2), x, y);
			x++;
		}
		y++;
	}
}
