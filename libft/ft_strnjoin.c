/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 19:10:43 by sraphard          #+#    #+#             */
/*   Updated: 2020/06/10 19:10:54 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char *dst, char *src, int nb)
{
	char	*new;
	int		i;
	int		j;

	if (nb < 0)
		nb = 0;
	if (!(new = malloc((ft_strlen(dst) + nb + 1) * sizeof(char))))
		return (0);
	i = -1;
	j = 0;
	while (dst[++i])
		new[i] = dst[i];
	while (j < nb && src[j])
	{
		new[i + j] = src[j];
		j++;
	}
	new[i + j] = 0;
	free(dst);
	return (new);
}
