/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:50:23 by user42            #+#    #+#             */
/*   Updated: 2020/10/30 11:24:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_get_dir(char c, t_eng *eng)
{
	if (c == 'N')
	{
		eng->dir[0] = -1;
		eng->dir[1] = 0;	
		eng->cam[0] = 0;	
		eng->cam[1] = 0.66;	
	}
	else if (c == 'S')
	{
		eng->dir[0] = 1;
		eng->dir[1] = 0;	
		eng->cam[0] = 0;	
		eng->cam[1] = -0.66;	
	}
	else if (c == 'E')
	{
		eng->dir[0] = 0;
		eng->dir[1] = 1;	
		eng->cam[0] = 0.66;	
		eng->cam[1] = 0;	
	}
	else if (c == 'W' || c == 'O')
	{
		eng->dir[0] = 0;
		eng->dir[1] = -1;
		eng->cam[0] = -0.66;	
		eng->cam[1] = 0;	
	}
}

static void	ft_get_txtr(t_mega *mega, t_map *map, t_txtr *ttr, int i)
{
	ttr->path = ft_strdup(map->txtr[i]);
	ttr->addr = mlx_xpm_file_to_image(mega->mlxp, ttr->path, &ttr->w, &ttr->h);
	ttr->data = mlx_get_data_addr(ttr->addr, &ttr->bpp, &ttr->sline, &ttr->endian);
}

void		ft_get_start(t_mega *mega, t_map *map, t_eng *eng)
{
	int	x;
	int	y;
	char	c;
	int	i;

	x = 0;
	c = 0;
	while (map->map[x][0])
	{

		y = 0;
		while (!ft_strchr("NSEOW", map->map[x][y]) && map->map[x][y])
			y++;
		if (ft_strchr("NESOW", map->map[x][y]) && map->map[x][y])
		{
			c = map->map[x][y];
			break;
		}
		x++;
	}
	eng->step = 0.08;
	eng->turn = 0.04;
	ft_get_dir(c, eng);
	i = -1;
	while (++i < 5)
		ft_get_txtr(mega, map, &map->ttr[i], i);
	eng->pos[0] = x + 0.8;
	eng->pos[1] = y + 0.8;
}

int	ft_get_color(int rgb[3])
{
	return (65536 * rgb[0] + 256 * rgb[1] + rgb[2]);
}

int	ft_raycast_start(t_mega *mega)
{
	ft_raycast(mega, &mega->eng, &mega->map, -1);
	return (0);
}
