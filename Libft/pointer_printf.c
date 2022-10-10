/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 08:55:47 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/22 16:53:36 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pointer_printf(long unsigned int n, char *str, int fd)
{
	int	a;

	if (n == 0)
	{
		putstr_printf("(nil)", fd);
		return (5);
	}
	else
	{
		a = 2;
		putstr_printf("0x", 1);
		a = a + puthexa_printf(n, str, fd);
	}
	return (a);
}
