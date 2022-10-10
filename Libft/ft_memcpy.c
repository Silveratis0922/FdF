/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:36:35 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/22 12:21:53 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char		*str2;
	const char	*str1;	
	size_t		i;

	str2 = dest;
	str1 = src;
	i = 0;
	while (i < size)
	{
		str2[i] = str1[i];
		i++;
	}
	return (dest);
}
/*
int	main()
{
	char num1[] = "ploum ploum";
	char str [] = "qwertyuiopasdfgh";

	ft_memcpy(str,num1, 6);
	printf("%s\n", str);
	return (0);
}*/
