/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:19:20 by sraphard          #+#    #+#             */
/*   Updated: 2020/09/22 18:56:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_key_press(int keycode, t_mega *mega)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(mega->mlxp, mega->win);
		exit(0);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_mega	mega;

	(void)ac;
	if (!ft_map_parse(&mega.map, av[1]))
		return (ft_free_map(&mega.map));
	ft_get_start(&mega);
	mega.mlxp = mlx_init();
	mega.win = mlx_new_window(mega.mlxp, mega.map.res[0], mega.map.res[1], "CUB3D");
	mlx_hook(mega.win, 3, 2, ft_key_press, &mega);
	ft_raycast(&mega, &(mega.eng), &(mega.map), -1);
	mlx_loop(mega.mlxp);
	ft_free_map(&mega.map);
}
