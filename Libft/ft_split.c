/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchantro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:12:23 by tchantro          #+#    #+#             */
/*   Updated: 2022/10/10 15:51:34 by tchantro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*tab_line(const char *s, int i, int j)
{
	int		k;
	char	*str;

	k = 0;
	str = malloc(sizeof(char) * j + 1);
	if (!str)
		return (0);
	while (k < j)
	{
		str[k] = s[i - j];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}

static int	word_count(const char *s, char c)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	j = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == c)
			j = 0;
		if (s[i] != c)
			j++;
		if (j == 1)
			word++;
		i++;
	}
	return (word + 1);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		a;
	char	**str;

	i = -1;
	j = 0;
	a = 0;
	str = malloc(sizeof(char *) * word_count(s, c));
	if (!str)
		return (0);
	while (s[++i])
	{
		if (s[i] == c && j > 0)
		{
			str[a++] = tab_line(s, i, j);
			j = 0;
		}
		else if (s[i] != c)
			j++;
	}
	if (j > 0)
		str[a++] = tab_line(s, i, j);
	str[a++] = '\0';
	return (str);
}
/*
int	main()
{
	char **tab = ft_split("a123a456a78a", 'a');
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}*/
