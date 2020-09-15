/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:50:23 by user42            #+#    #+#             */
/*   Updated: 2020/09/14 14:00:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_hooks(t_hooks *hooks, void *mlxp, void *window, int hook)
{
	hooks->mlxp = mlxp;
	hooks->window = window;
	hooks->hook = hook;
}
