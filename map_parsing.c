/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 15:51:41 by sraphard          #+#    #+#             */
/*   Updated: 2020/09/07 16:58:47 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_fill_clr(t_map *map, int i, char *line)
{
	int j;

	j = -1;
	if (*line == 'F')
	{
		while (ft_iswhite(line[i]))
			i++;
		while (++j < 3)
		{
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
			map->ceiling[j] = ft_atoi(line + i);
			i += ft_nbrlen(map->ceiling[j]) + 1;
		}
	}
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

static void	ft_fill_para(char *line, t_map *map, int i)
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
		map->txtr[ft_get_txt(line)] = ft_strtrim(line + i, " \t");
	}
	if (*line == 'F' || *line == 'C')
	{
		ft_fill_clr(map, 2, line);
	}

}

void	trash(t_map *map)
{
	printf("R -- %d %d\nNO -- %s\nSO -- %s\nWE -- %s\nEA -- %s\nS -- %s\nF -- %i,%i,%i\nC -- %i,%i,%i\n", map->res[0], map->res[1], map->txtr[0], map->txtr[1], map->txtr[2], map->txtr[3], map->txtr[4], map->floor[0], map->floor[1], map->floor[2], map->ceiling[0], map->ceiling[1], map->ceiling[2]);
}

int	main(int ac, char **av)
{
	int	fd;
	char	*line;
	t_map	map ;

	line = NULL;
	ft_init_map(&map);
	(void)ac;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line))
	{
		while (!*line)
			get_next_line(fd, &line);
		if (!ft_check_map(line, fd))
			return (0);
		ft_fill_para(line, &map, 0);
	}
	trash(&map);
	close(fd);
	return (0);
}
