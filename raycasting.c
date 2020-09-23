/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 12:59:04 by user42            #+#    #+#             */
/*   Updated: 2020/09/23 14:17:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
		eng->Ddist[0] = (eng->Dpos[0] + 1.0 - eng->pos[0]) * eng->Ddelta[0];
	}
	if (eng->ray[1] < 0)
	{
		eng->Dstep[1] = -1;
		eng->Ddist[1] = (eng->pos[1] - eng->Dpos[1]) * eng->Ddelta[1];
	}
	else
	{
		eng->Dstep[1] = 1;
		eng->Ddist[1] = (eng->Dpos[1] + 1.0 - eng->pos[1]) * eng->Ddelta[1];
	}
}

static void	ft_DDA(t_eng *eng, t_map *map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if(eng->Ddist[0] < eng->Ddist[1])
		{
			eng->Ddist[0] += eng->Ddelta[0];
			eng->Dpos[0] += eng->Dstep[0];
			eng->side = 0;
		}
		else
		{
			eng->Ddist[1] += eng->Ddelta[1];
			eng->Dpos[1] += eng->Dstep[1];
			eng->side = 1;
		}
		if(map->map[eng->Dpos[0]][eng->Dpos[1]] > 0) hit = 1;
	}
}

static void	ft_draw_screen(t_mega *mega, int Wmin, int Wmax, int x)
{
	int	y;

	y = -1;
	printf("%d %d\n", Wmin, Wmax);
	while (++y < Wmin)
	mlx_pixel_put(mega->mlxp, mega->win, x, y, ft_get_color(mega->map.floor));
	while (++y < Wmax)
	mlx_pixel_put(mega->mlxp, mega->win, x, y, 0xFF2D00);
	while (++y < mega->map.res[1])
	mlx_pixel_put(mega->mlxp, mega->win, x, y, ft_get_color(mega->map.ceiling));
}

static void	ft_draw_wall(t_eng *eng, t_map *map, t_mega *mega, int x)
{
	int	Wheight;
	int	Wmin;
	int	Wmax;

	Wheight = (int)(map->res[1] / eng->Wdist);
	Wmin = (-1 *Wheight) / 2 + map->res[1] / 2;
	Wmin < 0 ? Wmin = 0 : 0;
	Wmax = Wheight / 2 + map->res[1] / 2;
	Wmax >= map->res[1] ? Wmax = map->res[1] - 1 : 0;
	printf("%d --", x);

	ft_draw_screen(mega, Wmin, Wmax, x);
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
		eng->Ddelta[0] = (eng->ray[1] == 0) ? 0 : ((eng->ray[0]) ? 1 : abs(1 / eng->ray[0]));
		eng->Ddelta[1] = (eng->ray[0] == 0) ? 0 : ((eng->ray[1]) ? 1 : abs(1 / eng->ray[1]));
		ft_step(eng);
		ft_DDA(eng, map);
		if (eng->side == 0)
			eng->Wdist = (eng->Dpos[0] - eng->pos[0] + (1 - eng->Dstep[0]) / 2) / eng->ray[0];
		else
			eng->Wdist = (eng->Dpos[1] - eng->pos[1] + (1 - eng->Dstep[1]) / 2) / eng->ray[1];
		ft_draw_wall(eng, map, mega, x);
	}
}
