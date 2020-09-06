/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:13:37 by sraphard          #+#    #+#             */
/*   Updated: 2019/11/14 20:57:08 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_get_word_count(char const *s, char c)
{
	int	i;
	int	r;

	i = -1;
	r = 0;
	while (s[++i])
		if (s[i] && s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			r++;
	return (r);
}

static int	*ft_get_each_size_word(char const *s, char c)
{
	int	*tab;
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	if (!(tab = malloc(ft_get_word_count(s, c) * sizeof(int))))
		return (0);
	while (s[++i])
		if (s[i] && s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
		{
			j = 0;
			tab[k] = 0;
			while ((s + (i - j)) >= s && s[i - j] != c)
			{
				tab[k]++;
				j++;
			}
			k++;
		}
	return (tab);
}

char		**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	if (!s || (!(tab = malloc((ft_get_word_count(s, c) + 1) * sizeof(char *)))))
		return (0);
	tab[ft_get_word_count(s, c)] = 0;
	while (s[++i] && i < (int)ft_strlen(s))
	{
		k = 0;
		if (s[i] && s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
		{
			if (!(tab[j] = malloc((ft_get_each_size_word(s, c)[j] + 1)
													* sizeof(char))))
				return (0);
			i -= ft_get_each_size_word(s, c)[j] - 1;
			while (s[i] && s[i] != c)
				tab[j][k++] = s[i++];
			tab[j++][k] = 0;
		}
	}
	return (tab);
}
