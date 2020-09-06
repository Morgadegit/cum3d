/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:53:14 by sraphard          #+#    #+#             */
/*   Updated: 2019/11/10 20:44:26 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*nav;
	t_list	*tofree;

	if (!lst || !del)
		return ;
	nav = *lst;
	while (nav)
	{
		tofree = nav;
		nav = nav->next;
		del(tofree->content);
		free(tofree);
	}
	*lst = NULL;
}
