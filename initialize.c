/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 10:53:06 by tchantro          #+#    #+#             */
/*   Updated: 2022/10/10 12:15:25 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	initialize(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (1);
	data->win = mlx_new_window(data->mlx, WIN_X, WIN_Y, "C'est samedi");
	if (data->win == NULL)
	{
		free(data->win);
		return (2);
	}
	return (0);
}

int	**init_map_x(t_data *data)
{
	int	y;

	data->map_x = malloc(sizeof (int *) * data->size.y);
	if (!data->map_x)
		return (NULL);
	y = 0;
	while (y < data->size.y)
	{
		data->map_x[y] = malloc (sizeof (int) * data->size.x);
		if (!data->map_x)
			return (NULL);
		y++;
	}
	return (data->map_x);
}

int	**init_map_y(t_data *data)
{
	int	y;

	data->map_y = malloc (sizeof (int *) * data->size.y);
	if (!data->map_y)
		return (NULL);
	y = 0;
	while (y < data->size.y)
	{
		data->map_y[y] = malloc (sizeof (int) * data->size.x);
		if (!data->map_y)
			return (NULL);
		y++;
	}
	return (data->map_y);
}
