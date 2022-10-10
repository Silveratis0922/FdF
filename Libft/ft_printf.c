/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 14:10:08 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/22 16:49:37 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	converts(const char *s, int i, va_list args)
{
	if (s[i] == 'c')
		return (putchar_printf(va_arg(args, int), 1));
	else if (s[i] == 's')
		return (putstr_printf(va_arg(args, char *), 1));
	else if (s[i] == 'p')
		return (pointer_printf(va_arg(args, long unsigned int),
				"0123456789abcdef", 1));
	else if (s[i] == 'd' || s[i] == 'i')
		return (putnbr_printf(va_arg(args, int), 1));
	else if (s[i] == 'u')
		return (putnbr_unsigned_printf(va_arg(args, unsigned int), 1));
	else if (s[i] == 'x')
		return (puthexa_printf(va_arg(args, unsigned int),
				"0123456789abcdef", 1));
	else if (s[i] == 'X')
		return (puthexa_printf(va_arg(args, unsigned int),
				"0123456789ABCDEF", 1));
	else if (s[i] == '%')
		return (putchar_printf('%', 1));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		size;

	size = 0;
	va_start(args, s);
	i = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			putchar_printf(s[i], 1);
			size++;
		}
		else if (s[i] == '%')
		{
			i++;
			size = size + converts(s, i, args);
		}
		i++;
	}
	va_end(args);
	return (size);
}
/*
int	main()
{
	char	*str = "blabla";
	printf("%d\n", ft_printf("test p:%p", &str));
	printf("%d\n", printf("test p:%p", &str));
	return (0);
}*/
