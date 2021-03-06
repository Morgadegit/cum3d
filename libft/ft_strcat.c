/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:54:25 by sraphard          #+#    #+#             */
/*   Updated: 2020/03/04 18:54:29 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, char *src)
{
	int	i;
	int	j;

	i = ft_strlen(dst);
	j = 0;
	while (src[j])
		dst[i++] = src[j++];
	dst[i] = 0;
	return (dst);
}
