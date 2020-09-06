/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_to_hex_convert.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:55:37 by sraphard          #+#    #+#             */
/*   Updated: 2020/03/07 15:56:08 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fill_binary_table(char *number)
{
	char	*tab;
	int		i;

	tab = malloc(5 * sizeof(char));
	i = 0;
	tab[5] = 0;
	while (i < 4)
	{
		tab[i] = *(number + i);
		i++;
	}
	return (tab);
}

static char	*ft_get_correspondance_bis(char *bits)
{
	if (ft_strcmp(bits, "1000"))
		return (ft_strdup("8"));
	else if (ft_strcmp(bits, "1001"))
		return (ft_strdup("9"));
	else if (ft_strcmp(bits, "1010"))
		return (ft_strdup("a"));
	else if (ft_strcmp(bits, "1011"))
		return (ft_strdup("b"));
	else if (ft_strcmp(bits, "1100"))
		return (ft_strdup("c"));
	else if (ft_strcmp(bits, "1101"))
		return (ft_strdup("d"));
	else if (ft_strcmp(bits, "1110"))
		return (ft_strdup("e"));
	else if (ft_strcmp(bits, "1111"))
		return (ft_strdup("f"));
	return (0);
}

static char	*ft_get_correspondance(char *bits)
{
	if (ft_strcmp(bits, "0000"))
		return (ft_strdup("0"));
	else if (ft_strcmp(bits, "0001"))
		return (ft_strdup("1"));
	else if (ft_strcmp(bits, "0010"))
		return (ft_strdup("2"));
	else if (ft_strcmp(bits, "0011"))
		return (ft_strdup("3"));
	else if (ft_strcmp(bits, "0100"))
		return (ft_strdup("4"));
	else if (ft_strcmp(bits, "0101"))
		return (ft_strdup("5"));
	else if (ft_strcmp(bits, "0110"))
		return (ft_strdup("6"));
	else if (ft_strcmp(bits, "0111"))
		return (ft_strdup("7"));
	else
		return (ft_get_correspondance_bis(bits));
}

char		*ft_binary_to_hex_convert(char *number)
{
	char	*bits;
	char	*result;
	int		i;

	i = 0;
	result = ft_strdup("");
	while (number[i])
	{
		bits = ft_fill_binary_table(number + i);
		result = ft_strjoin(result, ft_get_correspondance(bits), 0);
		i += 4;
	}
	free(bits);
	return (result);
}
