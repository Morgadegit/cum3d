/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 19:41:41 by sraphard          #+#    #+#             */
/*   Updated: 2020/03/07 18:28:39 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strjoin_c(char *s, char c)
{
	int		i;
	char	*new;

	i = -1;
	if (!s || !c)
		return (0);
	if (!(new = malloc((ft_strlen(s) + 2) * sizeof(char))))
		return (0);
	while (s[++i])
		new[i] = s[i];
	new[i] = c;
	new[i + 1] = 0;
	free(s);
	return (new);
}
