/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:48:04 by sraphard          #+#    #+#             */
/*   Updated: 2019/11/14 21:08:49 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_getstart(char const *s, char const *set)
{
	int i;
	int start;

	i = 0;
	start = 0;
	while (s[i] && ft_strchr(set, s[i]))
	{
		start++;
		i++;
	}
	return (start);
}

static int		ft_getend(char const *s, char const *set)
{
	int i;
	int end;

	i = ft_strlen(s) - 1;
	end = i;
	while ((s + i >= s) && ft_strchr(set, s[i]))
	{
		end--;
		i--;
	}
	return (end);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		i;
	int		j;

	if (!s1)
		return (0);
	else if (!set)
		return ((char *)s1);
	i = ft_getstart(s1, set);
	j = 0;
	if (i > ft_getend(s1, set))
	{
		new = malloc(sizeof(char));
		new[0] = 0;
		return (new);
	}
	if (!(new = malloc((ft_getend(s1, set) - i) * sizeof(char) + 2)))
		return (0);
	while (s1[i] && i <= ft_getend(s1, set))
		new[j++] = s1[i++];
	new[j] = 0;
	return (new);
}
