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

void		ft_get_start(t_mega *mega)
{
	int	x;
	int	y;
	char	c;

	x = 0;
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
	mega->eng.step = 0.05;
	mega->eng.turn = 0.02;
	ft_get_dir(c, &(mega->eng));
	mega->eng.pos[0] = x;
	mega->eng.pos[1] = y;
	printf("%d, %d\n", x, y);
}

int	ft_get_color(int rgb[3])
{
	return (65536 * rgb[0] + 256 * rgb[1] + rgb[2]);
}
