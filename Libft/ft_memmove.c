/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:09:39 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/22 12:22:19 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char		*str1;
	char		*str2;
	size_t		i;

	str2 = dest;
	str1 = (char *)src;
	if (str1 == str2 || size == 0)
		return (dest);
	if (str2 > str1)
	{
		i = size;
		while ((int)i-- > 0)
			str2[i] = str1[i];
	}
	if (str1 > str2)
	{
		i = 0;
		while (i < size)
		{
			str2[i] = str1[i];
			i++;
		}
	}
	return (dest);
}
/*
int	main()
{
	char src[] = "lorem ipsum dolor sit amet";
	char *dest;

	dest = src + 1;
	printf("%s\n", (char *)ft_memmove(src, dest, 8));
	printf("%s\n", (char *)memmove(src, dest, 8));
	return (0);
}*/
