/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:51:41 by sraphard          #+#    #+#             */
/*   Updated: 2020/09/06 15:57:47 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_clr(int state, t_map *map, int i, char *line)
{
	int j;

	j = -1;
	if (state == 6)
	{
		while (ft_iswhite(line[i]))
			i++;
		while (++j < 3)
		{
			map->floor[j] = ft_atoi(line + i);
			i += ft_nbrlen(map->floor[j]) + 1;
		}
	}
	if (state == 7)
	{
		while (ft_iswhite(line[i]))
			i++;
		while (++j < 3)
		{
			map->ceiling[j] = ft_atoi(line + i);
			i += ft_nbrlen(map->ceiling[j]) + 1;
		}
	}
}

void	ft_fill_para(int state, char *line, t_map *map, int i)
{
	if (state == 0)
	{
		while (!(ft_isdigit(line[i])))
			i++;
		map->res[0] = ft_atoi(line + i);
		i += ft_nbrlen(map->res[0]);
		while (!(ft_isdigit(line[i])))
			i++;
		map->res[1] = ft_atoi(line + i);
	}
	if (ft_is_btwn(state, 1, 5))
	{
		i = 2;
		while (ft_iswhite(line[i]))
			i++;
		map->txtr[state - 1] = ft_strtrim(line + i, " \t");
	}
	if (state == 6 || state == 7)
	{
		ft_fill_clr(state, map, 2, line);
	}
}

void	trash(t_map *map)
{
	printf("%d %d\n%s\n%s\n%s\n%s\n%s\n%i,%i,%i\n%i,%i,%i\n", map->res[0], map->res[1], map->txtr[0], map->txtr[1], map->txtr[2], map->txtr[3], map->txtr[4], map->floor[0], map->floor[1], map->floor[2], map->ceiling[0], map->ceiling[1], map->ceiling[2]);
}

int	main()
{
	int	fd;
	char	*line;
	t_map	map;
	int	state;

	line = NULL;
	ft_init_map(&map);
	fd = open("map.cub", O_RDONLY);
	state = 0;
	while (get_next_line(fd, &line))
	{
		while (!*line)
			get_next_line(fd, &line);
		if (!ft_check_line(state, line, fd))
			return (0);
		ft_fill_para(state, line, &map, 0);
		state++;
	}
	trash(&map);
	close(fd);
	return (0);
}
