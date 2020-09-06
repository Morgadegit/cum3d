/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:34:00 by sraphard          #+#    #+#             */
/*   Updated: 2020/06/11 21:30:11 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!s || !(new = malloc(len * sizeof(char) + 1)))
		return (0);
	if (start > (size_t)ft_strlen(s))
	{
		new[0] = 0;
		return (new);
	}
	while (i < len)
		new[i++] = s[start++];
	new[i] = 0;
	return (new);
}
