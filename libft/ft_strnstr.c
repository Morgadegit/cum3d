/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:31:17 by sraphard          #+#    #+#             */
/*   Updated: 2019/11/14 20:57:44 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "./libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (needle[0] == 0 || !needle)
		return ((char *)haystack);
	if (len < 1)
		return (0);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] && needle[j] &&
				haystack[i + j] == needle[j])
		{
			if (i + j > len)
				return (NULL);
			j++;
		}
		if (!needle[j] && i + j <= len)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
