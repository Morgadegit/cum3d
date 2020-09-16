/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 19:36:12 by user42            #+#    #+#             */
/*   Updated: 2020/09/15 14:02:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_map(t_map *map)
{
	int	i;

	i = -1;
	map->res[0] = -1;
	map->res[1] = -1;
	while (++i < 5)
		map->txtr[i] = ft_strdup("");
	i = -1;
	while (++i < 3)
		map->floor[i] = -1;
	i = -1;
	while (++i < 3)
		map->ceiling[i] = -1;
	map->mlxp = NULL;
	map->window = NULL;
}

int	ft_free_map(t_map *map)
{
	int	i;

	i = 5;
	while (--i >= 0)
		free(map->txtr[i]);
        return (0);
}

int	ft_err(int err)
{
	if (err == 0)
		ft_putstr_fd("Error\nInvalid .cub file.", 2);
	else if (err == 1)
		ft_putstr_fd("Error\nInvalid Resolution.", 2);
	else if (err == 2)
		ft_putstr_fd("Error\nInvalid Texture.", 2);
	else if (err == 3)
		ft_putstr_fd("Error\nInvalid Floor Colour.", 2);
	else if (err == 4)
		ft_putstr_fd("Error\nRepeating Map Parameters.", 2);
	else if (err == 5)
		ft_putstr_fd("Error\nInvalid Map Parameters.", 2);
	else if (err == 6)
		ft_putstr_fd("Error\nInvalid Ceiling Colour.", 2);
	return (0);
}

void	trash(t_map *map)
{
printf("R -- %d %d\nNO -- %s\nSO -- %s\nWE -- %s\nEA -- %s\nS -- %s\nF -- %i,%i,%i\nC -- %i,%i,%i\n", map->res[0], map->res[1], map->txtr[0], map->txtr[1], map->txtr[2], map->txtr[3], map->txtr[4], map->floor[0], map->floor[1], map->floor[2], map->ceiling[0], map->ceiling[1], map->ceiling[2]);
}