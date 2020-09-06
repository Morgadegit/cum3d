/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:59:02 by sraphard          #+#    #+#             */
/*   Updated: 2020/02/11 19:51:26 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_nsize(int n)
{
	int i;

	i = 1;
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n *= -1;
	while ((n / 10) > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char		*ft_print(int n, int size, char *new)
{
	if (n < 0)
	{
		new[0] = '-';
		new[size + 1] = 0;
		n *= -1;
		while (size > 0)
		{
			new[size] = (n % 10) + 48;
			n /= 10;
			size--;
		}
	}
	else if (n > 0)
	{
		new[size] = 0;
		while (size > 0)
		{
			new[size - 1] = (n % 10) + 48;
			n /= 10;
			size--;
		}
	}
	return (new);
}

char			*ft_itoa(int n)
{
	char	*new;
	int		size;

	size = ft_nsize(n);
	if (n == 0)
		new = ft_strdup("0");
	else if (n == -2147483648)
		new = ft_strdup("-2147483648");
	else
	{
		if (!(new = malloc((size + 1 + (n < 0 ? 1 : 0)) * sizeof(char))))
			return (0);
		new = ft_print(n, size, new);
	}
	return (new);
}
