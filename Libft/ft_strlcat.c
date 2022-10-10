/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:48:51 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/22 12:28:39 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	unsigned int	a;

	i = 0;
	j = ft_strlen(dest);
	k = ft_strlen(src);
	a = ft_strlen(dest);
	if (size <= j || size == 0)
		return (k + size);
	if (size > (j + k))
		size = (j + k + 1);
	while (i < (size - j - 1))
	{
		dest[a] = src[i];
		a++;
		i++;
	}
	dest[a] = '\0';
	return (j + k);
}
