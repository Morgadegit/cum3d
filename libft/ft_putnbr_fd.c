/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:11:56 by sraphard          #+#    #+#             */
/*   Updated: 2020/01/22 20:34:16 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./libft.h"

static void	actual_put_nbr(int nb, long i, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
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

void		ft_putnbr_fd(int nb, int fd)
{
	long	i;

	i = 1;
	if (nb <= -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (nb == 0)
	{
		ft_putchar_fd(48, fd);
		return ;
	}
	actual_put_nbr(nb, i, fd);
}
