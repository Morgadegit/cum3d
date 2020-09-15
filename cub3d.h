/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 18:02:57 by sraphard          #+#    #+#             */
/*   Updated: 2020/09/14 14:01:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"

typedef	struct	s_map
{
	int	res[2];
	char	*txtr[5];
	int	floor[3];
	int	ceiling[3];
	int	*map;
	void	*mlxp;
	void	*window;
}		t_map;
typedef struct	s_hooks
{
	void	*mlxp;
	void	*window;
	int	hook;
}		t_hooks;
int		ft_map_parse(t_map *map, char *cub);
void		ft_init_map(t_map *map);
int		ft_check_map(char *line);
int		ft_free_map(t_map *map);
int		ft_err(int err);
void		ft_get_hooks(t_hooks *hooks, void *mlxp, void *window, int hook);
void		trash(t_map *map);
#endif
