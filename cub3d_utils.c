/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 15:59:36 by sraphard          #+#    #+#             */
/*   Updated: 2020/09/10 13:37:07 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_map(t_map *map)
{
	int	i;

	i = -1;
	map->res[0] = 0;
	map->res[1] = 0;
	while (++i < 5)
		map->txtr[i] = ft_strdup("");
	i = -1;
	while (++i < 3)
		map->floor[i] = 0;
	i = -1;
	while (++i < 3)
		map->ceiling[i] = 0;
}

int	ft_free_map(t_map *map)
{
	int	i;

	i = 5;
	while (--i >= 0)
		free(map->txtr[i]);
        return (0);
}

void	trash(t_map *map)
{
printf("R -- %d %d\nNO -- %s\nSO -- %s\nWE -- %s\nEA -- %s\nS -- %s\nF -- %i,%i,%i\nC -- %i,%i,%i\n", map->res[0], map->res[1], map->txtr[0], map->txtr[1], map->txtr[2], map->txtr[3], map->txtr[4], map->floor[0], map->floor[1], map->floor[2], map->ceiling[0], map->ceiling[1], map->ceiling[2]);
}
