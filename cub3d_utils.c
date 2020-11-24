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

static void	ft_ttr_init(t_txtr ttr)
{
	ttr.path = ft_strdup("");
	ttr.data = NULL;
	ttr.bpp = 0;
	ttr.sline = 0;
	ttr.endian = 0;
}

static void	ft_get_txtr(t_mega *mega, t_map map, t_txtr *ttr, int i)
{
	int	h;
	int	w;

	h = 50;
	w = 50;
	ft_strrep(&ttr->path, (map.txtr[i]));
	printf("%s\n", ttr->path);
	ttr->data = mlx_get_data_addr(ttr->addr = mlx_xpm_file_to_image(mega->mlxp, ttr->path, &w, &h), &ttr->bpp, &ttr->sline, &ttr->endian);
}

void		ft_get_start(t_mega *mega)
{
	int	x;
	int	y;
	char	c;
	int	i;

	x = 0;
	c = 0;
	i = -1;
	while (*(mega->map.map[x]))
	{
		y = 0;
		while (!ft_strchr("NSEOW", mega->map.map[x][y]) && mega->map.map[x][y])
			y++;
		if (ft_strchr("NESOW", mega->map.map[x][y]) && mega->map.map[x][y])
		{
			c = mega->map.map[x][y];
			break;
		}
		x++;
	}
	mega->eng.step = 0.08;
	mega->eng.turn = 0.04;
	ft_get_dir(c, &(mega->eng));
	while (++i < 5)
	{
		ft_ttr_init(mega->map.ttr[i]);
		ft_get_txtr(mega, mega->map, &mega->map.ttr[i], i);
	}
	mega->eng.pos[0] = x;
	mega->eng.pos[1] = y;
}

int	ft_get_color(int rgb[3])
{
	return (65536 * rgb[0] + 256 * rgb[1] + rgb[2]);
}
