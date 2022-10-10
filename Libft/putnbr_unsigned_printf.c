/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_unsigned_printf.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:39:13 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/22 16:46:34 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	nbr_len_unsigned(unsigned int n)
{
	unsigned int	i;

	i = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		i = i * 10;
	}
	return (i);
}

int	putnbr_unsigned_printf(unsigned int n, int fd)
{
	int		i;
	long	j;
	int		a;

	j = (long)n;
	i = nbr_len_unsigned(j);
	a = 0;
	while (i != 0)
	{
		putchar_printf(j / i + '0', fd);
		j = j % i;
		i = i / 10;
		a++;
	}
	return (a);
}
