/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:19:20 by sraphard          #+#    #+#             */
/*   Updated: 2020/10/28 10:54:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_rotate(int keycode, t_mega *mega, t_eng *eng)
{
	double	dirX;
	double	planeX;

	dirX = eng->dir[0];
	planeX = eng->cam[0];
	if (keycode == RIGHT)
	{
		eng->dir[0] = eng->dir[0] * cos(-(eng->turn)) - eng->dir[1] * sin(-(eng->turn));
		eng->dir[1] = dirX * sin(-(eng->turn)) + eng->dir[1] * cos(-(eng->turn));
		eng->cam[0] = eng->cam[0] * cos(-(eng->turn)) - eng->cam[1] * sin(-(eng->turn));
		eng->cam[1] = planeX * sin(-(eng->turn)) + eng->cam[1] * cos(-(eng->turn));
	}
	else if (keycode == LEFT)
	{
		eng->dir[0] = eng->dir[0] * cos(eng->turn) - eng->dir[1] * sin(eng->turn);
		eng->dir[1] = dirX * sin(eng->turn) + eng->dir[1] * cos(eng->turn);
		eng->cam[0] = eng->cam[0] * cos(eng->turn) - eng->cam[1] * sin(eng->turn);
		eng->cam[1] = planeX * sin(eng->turn) + eng->cam[1] * cos(eng->turn);
	}
	ft_raycast(mega, &(mega->eng), &(mega->map), -1);
}

static void	ft_move(int keycode, t_mega *mega, t_eng *eng, t_map *map)
{
	if (keycode == UP)
	{
		if (map->map[(int)(eng->pos[0] + eng->dir[0])][(int)(eng->pos[1])] != '1')
			eng->pos[0] += eng->dir[0] * eng->step;
		if (map->map[(int)(eng->pos[0])][(int)(eng->pos[1] + eng->dir[1])] != '1')
			eng->pos[1] += eng->dir[1] * eng->step;
	}
	else if (keycode == DOWN)
	{
		if (map->map[(int)(eng->pos[0] - eng->dir[0])][(int)(eng->pos[1])] != '1')
			eng->pos[0] -= eng->dir[0] * eng->step;
		if (map->map[(int)(eng->pos[0])][(int)(eng->pos[1] - eng->dir[1])] != '1')
			eng->pos[1] -= eng->dir[1] * eng->step;
	}
	ft_raycast(mega, &(mega->eng), &(mega->map), -1);
}

static int	ft_key_press(int keycode, t_mega *mega)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(mega->mlxp, mega->win);
		exit(0);
	}
	else if (keycode == LEFT || keycode == RIGHT)
		ft_rotate(keycode, mega, &(mega->eng));
	else if (keycode == UP || keycode == DOWN)
		ft_move(keycode, mega, &(mega->eng), &(mega->map));
	return (0);
}
int		main(int ac, char **av)
{
	t_mega	mega;

	(void)ac;
	if (!ft_map_parse(&mega.map, av[1]))
		return (ft_free_map(&mega.map));
	ft_get_start(&mega);
	mega.mlxp = mlx_init();
	mega.win = mlx_new_window(mega.mlxp, mega.map.res[0], mega.map.res[1], "CUB3D");
	ft_raycast(&mega, &(mega.eng), &(mega.map), -1);
	mlx_hook(mega.win, 3, 3, ft_key_press, &mega);
	mlx_loop(mega.mlxp);
	ft_free_map(&mega.map);
}
