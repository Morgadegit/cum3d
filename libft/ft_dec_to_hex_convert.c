/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex_convert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:04:34 by sraphard          #+#    #+#             */
/*   Updated: 2020/09/07 13:27:52 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

char		*ft_d_t_h_conv_p(unsigned long long x)
{
	char	*conv;
	char	*table;

	if (x == 0)
		return (NULL);
	conv = ft_strdup("");
	table = ft_strdup("0123456789abcdef");
	while (x)
	{
		conv = ft_strnjoin(conv, table + (x % 16), 1, 0);
		x /= 16;
	}
	free(table);
	return (ft_revert_array(conv));
}

char		*ft_dec_to_hex_convert(long x)
{
	char	*table;
	char	*conv;

	if (x == 0)
		return (ft_strdup("0"));
	conv = ft_strdup("");
	table = ft_strdup("0123456789abcdef");
	if (x < 0)
		x = UINT_MAX - (((x + 1) * -1));
	while (x)
	{
		conv = ft_strnjoin(conv, table + (x % 16), 1, 0);
		x /= 16;
	}
	free(table);
	return (ft_revert_array(conv));
}
