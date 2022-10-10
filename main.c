/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:09:03 by tchantro          #+#    #+#             */
/*   Updated: 2022/10/10 18:34:24 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		if (verif_arg(argv[1], ".fdf") == 1)
			return (write(2, "Error_arg\n", 10));
		data.map_z = read_file(argv[1], &data);
		if (!data.map_z)
			return (write (2, "Error_1\n", 8));
		data.map_x = init_map_x(&data);
		data.map_y = init_map_y(&data);
		if ((!data.map_x) || (!data.map_y))
			return (write (2, "Error_2\n", 8));
		if (initialize(&data) != 0)
			return (write (2, "Error_3\n", 8));
		mapping_iso_coor(&data);
		data.img.mlx_img = mlx_new_image(data.mlx, WIN_X, WIN_Y);
		data.img.adrs = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
		mlx_loop_hook(data.mlx, &test, &data);
		mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
		mlx_loop(data.mlx);
		destroy_malloc(&data);
	}
	return (0);
}
