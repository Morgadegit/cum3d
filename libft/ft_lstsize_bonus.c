/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 16:52:16 by sraphard          #+#    #+#             */
/*   Updated: 2019/11/12 20:46:26 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*nav;

	if (!lst)
		return (0);
	i = 0;
	nav = lst;
	while (nav)
	{
		nav = nav->next;
		i++;
	}
	return (i);
}
