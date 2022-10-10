/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:13:35 by tchantro          #+#    #+#             */
/*   Updated: 2022/06/02 17:01:47 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (*s2 == '\0' || !s2)
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		k = 0;
		j = i;
		while (s2[k] == s1[i] && i < n)
		{
			k++;
			i++;
		}
		if (s2[k] == '\0')
			return ((char *)s1 + i - k);
		i = j + 1;
	}
	return (0);
}
/*
int	main()
{
	char str[] = "aaabcabcd";
	char pls[] = "aabc";

	printf("%s\n", ft_strnstr(str, pls, -1));
	return (0);
}*/
