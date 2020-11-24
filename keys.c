#include "cub3d.h"

static void	ft_rotate(int keycode, t_mega *mega, t_eng *eng)
{
	double	dirX;
	double	planeX;

	dirX = eng->dir[0];
	planeX = eng->cam[0];
	if (keycode == RIGHT || keycode == D)
	{
		eng->dir[0] = eng->dir[0] * cos(-(eng->turn)) - eng->dir[1] * sin(-(eng->turn));
		eng->dir[1] = dirX * sin(-(eng->turn)) + eng->dir[1] * cos(-(eng->turn));
		eng->cam[0] = eng->cam[0] * cos(-(eng->turn)) - eng->cam[1] * sin(-(eng->turn));
		eng->cam[1] = planeX * sin(-(eng->turn)) + eng->cam[1] * cos(-(eng->turn));
	}
	else if (keycode == LEFT || keycode == Q)
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
	if (keycode == UP || keycode == Z)
	{
		if (map->map[(int)(eng->pos[0] + eng->dir[0])][(int)(eng->pos[1])] != '1')
			eng->pos[0] += eng->dir[0] * eng->step;
		if (map->map[(int)(eng->pos[0])][(int)(eng->pos[1] + eng->dir[1])] != '1')
			eng->pos[1] += eng->dir[1] * eng->step;
	}
	else if (keycode == DOWN || keycode == S)
	{
		if (map->map[(int)(eng->pos[0] - eng->dir[0])][(int)(eng->pos[1])] != '1')
			eng->pos[0] -= eng->dir[0] * eng->step;
		if (map->map[(int)(eng->pos[0])][(int)(eng->pos[1] - eng->dir[1])] != '1')
			eng->pos[1] -= eng->dir[1] * eng->step;
	}
	ft_raycast(mega, &(mega->eng), &(mega->map), -1);
}

static void	ft_strafe (int keycode, t_mega *mega, t_eng *eng, t_map *map)
{
	if (keycode == A)
	{
		if (map->map[(int)(eng->pos[0] + (eng->dir[0]))][(int)(eng->pos[1])] != '1')
			eng->pos[0] -= eng->dir[1] * eng->step;
		if (map->map[(int)(eng->pos[0])][(int)(eng->pos[1] + (eng->dir[1]))] != '1')
			eng->pos[1] -= -eng->dir[0] * eng->step;
	}
	else if (keycode == E)
	{
		if (map->map[(int)(eng->pos[0] + (eng->dir[0]))][(int)(eng->pos[1])] != '1')
			eng->pos[0] += eng->dir[1] * eng->step;
		if (map->map[(int)(eng->pos[0])][(int)(eng->pos[1] + (eng->dir[1]))] != '1')
			eng->pos[1] += -eng->dir[0] * eng->step;
	}
	ft_raycast(mega, &(mega->eng), &(mega->map), -1);
}

int		ft_key_press(int keycode, t_mega *mega)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(mega->mlxp, mega->win);
		kill(mega->pid, SIGTERM);
		exit(0);
	}
	else if (keycode == LEFT || keycode == RIGHT || keycode == D || keycode == Q)
		ft_rotate(keycode, mega, &(mega->eng));
	else if (keycode == UP || keycode == DOWN || keycode == S || keycode == Z)
		ft_move(keycode, mega, &(mega->eng), &(mega->map));
	else if (keycode == A || keycode == E)
		ft_strafe(keycode, mega, &(mega->eng), &(mega->map)); 
	return (0);
}

