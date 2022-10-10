/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:35:14 by tchantro          #+#    #+#             */
/*   Updated: 2022/09/22 12:28:22 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		a;
	char	*str;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	a = 0;
	str = malloc(sizeof (char) * (i + j) + 1);
	if (!str)
		return (0);
	i = 0;
	while (s1[i])
		str[a++] = s1[i++];
	j = 0;
	while (s2[j])
		str[a++] = s2[j++];
	str[a] = '\0';
	return (str);
}
