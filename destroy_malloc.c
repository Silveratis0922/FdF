/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_malloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:03:25 by tchantro          #+#    #+#             */
/*   Updated: 2022/10/10 16:13:07 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	destroy_malloc(t_data *data)
{
	int	y;

	y = 0;
	mlx_destroy_image(data->mlx, data->img.mlx_img);
	mlx_destroy_display(data->mlx);
	while (y < data->size.y)
	{
		free(data->map_x[y]);
		free(data->map_y[y]);
		free(data->map_z[y]);
		y++;
	}
	free(data->map_x);
	free(data->map_y);
	free(data->map_z);
	free(data->mlx);
}
