/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:51:41 by sraphard          #+#    #+#             */
/*   Updated: 2020/09/10 19:44:44 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_fill_clr(t_map *map, int i, char *line, int j)
{
	if (*line == 'F')
	{
		while (ft_iswhite(line[i]))
			i++;
		while (++j < 3)
		{
			if (map->floor[j] != -1)
				return (ft_err(4));
			map->floor[j] = ft_atoi(line + i);
			i += ft_nbrlen(map->floor[j]) + 1;
		}
	}
	else if (*line == 'C')
	{
		while (ft_iswhite(line[i]))
			i++;
		while (++j < 3)
		{
			if (map->ceiling[j] != -1)
				return (ft_err(4));
			map->ceiling[j] = ft_atoi(line + i);
			i += ft_nbrlen(map->ceiling[j]) + 1;
		}
	}
	return (1);
}

static int	ft_get_txt(char *line)
{
	if (!ft_strncmp(line, "NO", 2))
		return (0);
	else if (!ft_strncmp(line, "SO", 2))
		return (1);
	else if (!ft_strncmp(line, "WE", 2))
		return (2);
	else if (!ft_strncmp(line, "EA", 2))
		return (3);
	else if (*line == 'S')
		return (4);
	else
		return (0);
}

static int	ft_fill_para(char *line, t_map *map, int i)
{
	if (*line == 'R')
	{
		while (!(ft_isdigit(line[i])))
			i++;
		map->res[0] = ft_atoi(line + i);
		i += ft_nbrlen(map->res[0]);
		while (!(ft_isdigit(line[i])))
			i++;
		map->res[1] = ft_atoi(line + i);
	}
	if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) ||
	!ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2) || *line == 'S')
	{
		i = 2;
		if (!ft_strcmp("", map->txtr[ft_get_txt(line)]))
			return (ft_err(4));
		free(map->txtr[ft_get_txt(line)]);
		map->txtr[ft_get_txt(line)] = ft_strtrim(line + i, " \t");
	}
	if (*line == 'F' || *line == 'C')
		return (ft_fill_clr(map, 2, line, -1));
	return (1);
}

int		ft_map_parse(t_map *map, char *cub)
{
	int	fd;
	char	*line;

	line = NULL;
	ft_init_map(map);
	if ((fd = open(cub, O_RDONLY)) == -1)
		return (ft_err(0));
	while (get_next_line(fd, &line))
	{
		if (!ft_check_map(line))
			return (0);
		if (line)
			if (!ft_fill_para(line, map, 0))
				return (0);
		free(line);
	}
	free(line);
	trash(map);
	close(fd);
	return (0);
}
