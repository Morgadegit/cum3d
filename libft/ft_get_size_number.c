/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_size_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:19:51 by sraphard          #+#    #+#             */
/*   Updated: 2020/02/07 15:58:14 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_get_size_number(int i)
{
	unsigned int x;

	x = 0;
	if (i < 0)
	{
		i *= -1;
		x++;
	}
	while (i)
	{
		x++;
		i /= 10;
	}
	return (x);
}
