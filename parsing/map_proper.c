/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_proper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 11:59:55 by user42            #+#    #+#             */
/*   Updated: 2020/10/01 14:23:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_ismapfil(t_map *map)
{
	return (map->res[0] != -1 && map->res[1] != -1 &&
	!ft_strcmp(map->txtr[0], "") && !ft_strcmp(map->txtr[1], "") &&
	!ft_strcmp(map->txtr[2], "") && !ft_strcmp(map->txtr[3], "") &&
	!ft_strcmp(map->txtr[4], "") &&	map->floor[0] != -1 &&
	map->floor[1] != -1 && map->floor[2] != -1 && map->ceiling[0] != -1 &&
	map->ceiling[1] != -1 && map->ceiling[2] != -1);
}

int	ft_proper (t_map *map, char **line, int fd)
{
	int	row;

	row = 0;
	while (get_next_line(fd, line))
	{
		while (!ft_strlen(*line))
		{
			free(*line);
			get_next_line(fd, line);
		}
		map->map = ft_ralloc(map->map, row + 1);
		ft_strrep(&(map->map[row]), *line);
		free(*line);
		row++;
	}
	free(*line);
	for (int i = 0 ; i < row ; i++)
		printf("%s\n", map->map[i]);
	return (1);
}
