/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 18:04:06 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/22 16:47:15 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbr_len(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		i = i * 10;
	}
	return (i);
}

int	putnbr_printf(int n, int fd)
{
	int		i;
	long	j;
	int		a;

	j = (long)n;
	i = nbr_len(j);
	a = 0;
	if (j < 0)
	{
		j = -j;
		putchar_printf('-', fd);
	}
	while (i != 0)
	{
		putchar_printf(j / i + '0', fd);
		j = j % i;
		i = i / 10;
		a++;
	}
	if (n < 0)
		return (a + 1);
	return (a);
}
