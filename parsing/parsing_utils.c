/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 19:36:12 by user42            #+#    #+#             */
/*   Updated: 2020/10/01 14:26:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_free_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < 5)
		free(map->txtr[i]);
	i = -1;
	while (map->map[++i][0])
		free(map->map[i]);
	free(map->map[i]);
	free(map->map);
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

char	**ft_ralloc(char **ptr, int size)
{
	int	i;
	char	**new;

	i = -1;
	new = malloc((size + 1) * sizeof(char *));
	while (++i < size)
		new[i] = ft_strdup(ptr[i]);
	new[i] = ft_strdup("");
	return (new);
}
