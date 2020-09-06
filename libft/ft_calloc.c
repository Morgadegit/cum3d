/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:32:19 by sraphard          #+#    #+#             */
/*   Updated: 2019/10/31 14:58:23 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void		*p;
	size_t		i;

	i = 0;
	if (!(p = malloc(count * size)))
		return (0);
	while (i < size * count)
	{
		((char *)p)[i] = 0;
		i++;
	}
	return (p);
}
