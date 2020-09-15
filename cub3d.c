/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:19:20 by sraphard          #+#    #+#             */
/*   Updated: 2020/09/15 14:46:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_key_press(t_hooks *hooks)
{
	if (hooks->hook == 9)
		mlx_destroy_window(hooks->mlxp, hooks->window);
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map;
	void	*mlxp;
	void	*window;
	t_hooks	hooks;

	(void)ac;
	if (!ft_map_parse(&map, av[1]))
		return (ft_free_map(&map));
	mlxp = mlx_init();
	window = mlx_new_window (mlxp, map.res[0], map.res[1], "CUB3D");
	ft_get_hooks(&hooks, mlxp, window, 9);
	mlx_key_hook(mlxp, &ft_key_press, &hooks);
	mlx_loop(mlxp);
	ft_free_map(&map);
}
