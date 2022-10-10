/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:14:01 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/22 12:13:57 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t size)
{
	char	*str2;
	size_t	i;

	i = 0;
	str2 = str;
	while (i < size)
	{
		str2[i] = '\0';
		i++;
	}
}
/*
int	main()
{
	char lo[] = "ploum ploum";

	printf("%s\n", lo);
	ft_bzero(lo, 4);
	printf("%s\n", lo);
	return (0);
}*/
