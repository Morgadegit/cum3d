/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 11:56:30 by sraphard          #+#    #+#             */
/*   Updated: 2020/09/07 11:57:05 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft.h"

char	*ft_strndup(char const *s, int x)
{
	char	*dst;
	int		i;

	i = 0;
	if (!s || !(dst = malloc(x + 1 * sizeof(char))))
		return (0);
	while (x--)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
