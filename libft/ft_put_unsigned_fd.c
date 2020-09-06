/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 20:38:55 by sraphard          #+#    #+#             */
/*   Updated: 2020/01/25 19:41:27 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./libft.h"

void		ft_put_unsigned_fd(unsigned int nb, int fd)
{
	long	i;

	i = 1;
	while (i < nb)
		i *= 10;
	if (i != 1)
		i /= 10;
	if (((nb / i) % 10) == 0)
		ft_putchar_fd(fd, 49);
	while (i != 0)
	{
		ft_putchar_fd(((nb / i) % 10) + 48, fd);
		i /= 10;
	}
}
