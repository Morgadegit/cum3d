/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 12:59:04 by user42            #+#    #+#             */
/*   Updated: 2020/10/28 11:22:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_draw_ui(t_mega *mega, t_map *map)
{
	int	x;
	int	y;
	int	r;

	x = map->res[0] / 2 - map->res[0] / 20;
	y = map->res[1] / 2;
	r = 0;
	while (r++ < map->res[0] / 20)
		mlx_pixel_put(mega->mlxp, mega->win, x++, y, 0xffffff);
	x += map->res[0] / 25;
	r = 0;
	while (r++ < map->res[0] / 20)
		mlx_pixel_put(mega->mlxp, mega->win, x++, y, 0xffffff);
	x = map->res[0] / 2 + map->res[0] / 48;
	y = map->res[1] / 2 - map->res[1] / 14;
	r = 0;
	while (r++ < map->res[1] / 20)
		mlx_pixel_put(mega->mlxp, mega->win, x, y++, 0xffffff);
	y += map->res[1] / 25;
	r = 0;
	while (r++ < map->res[1] / 20)
		mlx_pixel_put(mega->mlxp, mega->win, x, y++, 0xffffff);
}

static void	ft_step(t_eng *eng)
{
	if (eng->ray[0] < 0)
	{
		eng->Dstep[0] = -1;
		eng->Ddist[0] = (eng->pos[0] - eng->Dpos[0]) * eng->Ddelta[0];
	}
	else
	{
		eng->Dstep[0] = 1;
		eng->Ddist[0] = (eng->Dpos[0] - eng->pos[0] + 1.0) * eng->Ddelta[0];
	}
	if (eng->ray[1] < 0)
	{
		eng->Dstep[1] = -1;
		eng->Ddist[1] = (eng->pos[1] - eng->Dpos[1]) * eng->Ddelta[1];
	}
	else
	{
		eng->Dstep[1] = 1;
		eng->Ddist[1] = (eng->Dpos[1] - eng->pos[1] + 1.0) * eng->Ddelta[1];
	}
}

static void	ft_DDA(t_eng *eng, t_map *map)
{
	while (1)
	{
		if (eng->Ddist[0] < eng->Ddist[1])
		{
			eng->Ddist[0] += eng->Ddelta[0];
			eng->Dpos[0] += eng->Dstep[0];
			eng->side = eng->ray[0] < 0 ? 0 : 1;
		}
		else
		{
			eng->Ddist[1] += eng->Ddelta[1];
			eng->Dpos[1] += eng->Dstep[1];
			eng->side = eng->ray[1] < 0 ? 2 : 3;
		}
		if (map->map[(int)eng->Dpos[0]][(int)eng->Dpos[1]] == '1')
			break;
	}
}

void		ft_raycast(t_mega *mega, t_eng *eng, t_map *map, int x)
{

	while (++x < map->res[0])
	{
		eng->scr = 2 * x / (double)(map->res[0]) - 1;
		eng->ray[0] = eng->dir[0] + eng->cam[0] * eng->scr;
		eng->ray[1] = eng->dir[1] + eng->cam[1] * eng->scr;
		eng->Dpos[0] = (int)(eng->pos[0]);
		eng->Dpos[1] = (int)(eng->pos[1]);
		eng->Ddelta[0] = !eng->ray[1] ? 0 : (!eng->ray[0] ? 1 : fabs(1 / eng->ray[0]));
		eng->Ddelta[1] = !eng->ray[0] ? 0 : (!eng->ray[1] ? 1 : fabs(1 / eng->ray[1]));
		ft_step(eng);
		ft_DDA(eng, map);
		if (eng->side < 2)
			eng->Wdist = (eng->Dpos[0] - eng->pos[0] + (1 - eng->Dstep[0]) / 2) / eng->ray[0];
		else
			eng->Wdist = (eng->Dpos[1] - eng->pos[1] + (1 - eng->Dstep[1]) / 2) / eng->ray[1];
		ft_draw_wall(eng, map, mega, x);
		ft_draw_ui(mega, map);
	}
}
