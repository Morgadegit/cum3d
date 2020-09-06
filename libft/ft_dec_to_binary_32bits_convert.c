/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_binary_32bits_convert.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:50:10 by sraphard          #+#    #+#             */
/*   Updated: 2020/01/25 19:33:13 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dec_to_binary_32bits_convert(char *number)
{
	char			*ret;
	int				i;
	int				j;

	if (!(ret = malloc(sizeof(char) * 33)))
		return (0);
	i = 33;
	j = ft_strlen(number);
	while (i-- >= 0)
		if (j >= 0)
			ret[i] = number[j--];
		else
			ret[i] = '0';
	return (ret);
}
