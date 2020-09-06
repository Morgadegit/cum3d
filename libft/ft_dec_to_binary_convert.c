/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_binary_convert.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:18:16 by sraphard          #+#    #+#             */
/*   Updated: 2020/01/25 19:41:18 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dec_to_binary_convert(int x)
{
	char	*ret;
	char	c;

	c = (x % 2) + 48;
	ret = ft_strdup("");
	while (x > 0)
	{
		ret = ft_strncat(ret, &c, 1);
		x /= 2;
	}
	return (ft_revert_array(ret));
}
