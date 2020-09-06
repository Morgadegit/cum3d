/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:42:10 by sraphard          #+#    #+#             */
/*   Updated: 2020/03/09 18:21:01 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft.h"

char	*ft_strjoin(char *s1, char *s2, int sw)
{
	int		i;
	int		j;
	char	*new;

	i = -1;
	if (!s1 || !s2)
		return (0);
	if (!(new = malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
					* sizeof(char))))
		return (0);
	while (s1[++i])
		new[i] = s1[i];
	j = -1;
	while (s2[++j])
		new[i + j] = s2[j];
	new[i + j] = 0;
	if (sw == 0 || sw == 2)
		free(s1);
	if (sw == 1 || sw == 2)
		free(s2);
	return (new);
}
