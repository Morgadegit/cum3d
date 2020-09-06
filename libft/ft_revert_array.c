/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revert_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:29:51 by sraphard          #+#    #+#             */
/*   Updated: 2020/03/06 18:20:48 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_revert_array(char *s)
{
	int		i;
	int		j;
	char	*rev;

	i = 0;
	j = ft_strlen(s) - 1;
	if (!s)
		return (0);
	if (!(rev = malloc((ft_strlen(s) + 1) * sizeof(char))))
		return (0);
	while (j >= 0)
	{
		rev[i] = s[j];
		i++;
		j--;
	}
	rev[i] = 0;
	free(s);
	return (rev);
}
