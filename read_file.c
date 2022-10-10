/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:23:06 by tchantro          #+#    #+#             */
/*   Updated: 2022/10/10 15:24:25 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	file_line(char *arg)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open(arg, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		else
			i++;
		free(str);
	}
	close(fd);
	return (i);
}

int	*mapping(char **split, t_data *data)
{
	int	*map;
	int	y;
	int	m_x;

	y = 0;
	m_x = 0;
	while (split[y])
		y++;
	map = malloc(sizeof (int) * y);
	if (!map)
		return (NULL);
	y = 0;
	while (split[y])
	{
		map[m_x] = ft_atoi(split[y]);
		free(split[y]);
		y++;
		m_x++;
	}
	data->size.x = m_x;
	return (map);
}

int	**read_file(char *arg, t_data *data)
{
	char	**split;
	char	*str;
	int		fd;
	int		**map;
	int		y;

	y = file_line(arg);
	fd = open(arg, O_RDONLY);
	map = malloc(sizeof (int *) * y);
	if (!map)
		return (NULL);
	data->size.y = y;
	y = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		split = ft_split(str, ' ');
		map[y] = mapping(split, data);
		y++;
		free(split);
		free(str);
	}
	close(fd);
	return (map);
}
