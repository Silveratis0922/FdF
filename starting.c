/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 12:16:41 by tchantro          #+#    #+#             */
/*   Updated: 2022/10/10 17:56:05 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	test(t_data *data)
{
	if (data->win == NULL)
		return (1);
	center_of_window(data, 0xffff);
	printing_pixel_horizontal(data);
	printing_pixel_vertical(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.mlx_img, 0, 0);
	return (0);
}
