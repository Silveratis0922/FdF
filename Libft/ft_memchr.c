/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:55:23 by tchantro          #+#    #+#             */
/*   Updated: 2022/06/02 18:41:27 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	size_t		i;

	i = 0;
	str = (void *)s;
	if (c == 0 && n == 0)
		return (0);
	while (i < n)
	{
		if (str[i] == (char)c)
			return ((void *)str + i);
		i++;
	}
	return (0);
}
/*
int	main()
{
	char one[] = "012345";
	printf("%s\n", (char *)ft_memchr(one, '2', 3));
	return (0);
}*/
