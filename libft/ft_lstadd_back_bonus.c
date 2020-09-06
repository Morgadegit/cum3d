/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:06:06 by sraphard          #+#    #+#             */
/*   Updated: 2019/11/10 20:45:10 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*nav;

	nav = *alst;
	if (!*alst)
		*alst = new;
	else
	{
		while (nav && nav->next)
			nav = nav->next;
		nav->next = new;
	}
}
