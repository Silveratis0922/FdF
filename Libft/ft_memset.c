/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:19:08 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/22 12:23:39 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t size)
{
	char	*str2;
	size_t	i;

	i = 0;
	str2 = str;
	while (i != size)
	{
		str2[i] = c;
		i++;
	}
	return (str2);
}
/*
int	main()
{
	char lit[] = "coucou toi !";

	printf("%s\n", lit);
	ft_memset(lit, 'v', 5);
	printf("%s\n", lit);
	memset(lit, 'v', 5);
	printf("%s\n", lit);
	return (0);
}*/
