/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:06:45 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/22 12:18:05 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len(int i)
{
	int	j;

	j = 0;
	if (i <= 0)
		j = 1;
	while (i != 0)
	{
		i = i / 10;
		j++;
	}
	return (j);
}

char	*ft_itoa(int i)
{
	int		j;
	long	a;
	char	*str;

	j = len(i);
	a = i;
	str = malloc (sizeof(char) * j + 1);
	if (!str)
		return (0);
	if (i < 0)
	{
		str[0] = '-';
		a = -a;
	}
	if (a == 0)
		str[0] = '0';
	str[j] = '\0';
	j--;
	while (a != 0)
	{
		str[j] = a % 10 + 48;
		a = a / 10;
		j--;
	}
	return (str);
}
/*
int	main()
{
	int i;

	i = -214748364;
	printf("%s\n", ft_itoa(i));
	return (0);
}*/
