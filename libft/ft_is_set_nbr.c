/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_set_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 20:04:22 by sraphard          #+#    #+#             */
/*   Updated: 2020/09/05 20:17:31 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	ft_is_set_nbr(int x, int size, ...)
{
	va_list set;

	va_start(set, size);
	while (size--)
		if (va_arg(set, int) == x)
		{
			va_end(set);
			return (1);
		}
	va_end(set);
	return (0);
}
