/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:01:19 by sraphard          #+#    #+#             */
/*   Updated: 2020/03/10 17:19:57 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

static int		ft_nsize(unsigned int n)
{
	int i;

	i = 1;
	while ((n / 10) > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char		*ft_print(unsigned int n, int size, char *new)
{
	new[size] = 0;
	while (size > 0)
	{
		new[size - 1] = (n % 10) + 48;
		n /= 10;
		size--;
	}
	return (new);
}

char			*ft_itoa_uns(unsigned int n)
{
	char	*new;
	int		size;

	size = ft_nsize(n);
	if (!(new = malloc((size + 1) * sizeof(char))))
		return (0);
	new = ft_print(n, size, new);
	return (new);
}
