/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:45:57 by tchantro          #+#    #+#             */
/*   Updated: 2022/10/03 18:14:08 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_gnlen(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen_gnl(str);
	if (str == NULL)
		return (0);
	while (str[i++] != '\n')
	{
		if (i > len)
			return (0);
	}
	return (i);
}

char	*ft_strndup_gnl(char *s, int size)
{
	char	*dest;
	int		j;

	j = 0;
	dest = malloc(sizeof (char) * size + 1);
	if (!dest)
		return (0);
	while (j < size)
	{
		dest[j] = s[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*gnl_bis(char *buff, char *stash, int fd)
{
	int	i;

	i = 1;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ft_gnlen(stash) == 0 && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		buff[i] = '\0';
		if (i <= 0 && stash == NULL)
			return (NULL);
		else if (i <= 0 && stash != NULL)
			break ;
		else
		{
			if (stash == NULL)
				stash = ft_strdup_gnl(buff);
			else
				stash = ft_strjoin_gnl(stash, buff);
		}
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*stash[1024];
	char		*line;
	int			len;

	stash[fd] = gnl_bis(buff, stash[fd], fd);
	if (stash[fd] == NULL)
		return (NULL);
	len = ft_gnlen(stash[fd]);
	if (ft_strlen_gnl(stash[fd]) == len || len == 0)
	{
		line = ft_strdup_gnl(stash[fd]);
		free(stash[fd]);
		stash[fd] = NULL;
	}
	else
	{
		line = ft_strndup_gnl(stash[fd], len);
		stash[fd] = ft_substr_gnl(stash[fd], len, ft_strlen(stash[fd]) - len);
		if (stash[fd] == NULL)
			return (NULL);
	}
	return (line);
}
/*
int	main()
{
	int        fd;
	char    *str;
	int        i;

	i = 0;
	fd = open("test", O_RDONLY);
	if (fd == -1)
		return (1);
	while (i++ < 28)
	{
		str = get_next_line(fd);
		printf("%s", str);
//		if (str == NULL)
//			break ;
		free(str);
	} 
	close(fd);
	return (0);
}*/
