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

static void	*ft_dance(t_mega *mega)
{
	mega->win = mlx_new_window(mega->mlxp, mega->map.res[0], mega->map.res[1], "CUB3D");
	ft_raycast(mega, &mega->eng, &mega->map, -1);
	mlx_hook(mega->win, 3, 3, ft_key_press, mega);
	mlx_loop(mega->mlxp);
	ft_free_map(&mega->map);
	return (NULL);
}

static void	ft_song(void)
{
	while (1)
		execlp("aplay", "aplay", "-q", "./music.wav", NULL);
}

int		main(int ac, char **av)
{
	t_mega	*mega;

	if (!(mega = malloc(sizeof(t_mega))))
		return (0);
	(void)ac;
	mega->mlxp = mlx_init();
	if (!ft_map_parse(&mega->map, av[1]))
		return (ft_free_map(&mega->map));
	ft_get_start(mega);
	mega->pid = fork();
	if (mega->pid == 0)
		ft_dance(mega);
	else
		ft_song();
}
