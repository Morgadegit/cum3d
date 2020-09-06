/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 15:59:36 by sraphard          #+#    #+#             */
/*   Updated: 2020/09/06 15:30:30 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_map(t_map *map)
{
	int	i;
	map = malloc(sizeof(t_map));
	i = 0;
	map->res[0] = 0;
	map->res[1] = 0;
	while (i++ <= 5)
		map->txtr[i] = ft_strdup("i");
	i = 0;
	while (i++ <= 3)
		map->floor[i] = 0;
	i = 0;
	while (i++ <= 3)
		map->ceiling[i] = 0;
}
