/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 13:39:08 by sraphard          #+#    #+#             */
/*   Updated: 2020/09/07 13:45:35 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "./libft.h"

char	*ft_strlstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (needle[0] == 0 || !needle)
		return ((char *)haystack);
	if (len < 1)
		return (0);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] && j < len &&
			haystack[i + j] == needle[j])
		{
			if (j > len)
				return (NULL);
			j++;
		}
		if (j >= len)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
