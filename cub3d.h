/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 18:02:57 by sraphard          #+#    #+#             */
/*   Updated: 2020/09/17 23:04:18 by user42           ###   ########.fr       */
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
	int	*mw;
	char	*map;
}		t_map;
typedef struct	s_mega
{
	t_map	map;
	void	*mlxp;
	void	*win;
	int	pos[2];
}		t_mega;
int		ft_map_parse(t_map *map, char *cub);
void		ft_init_map(t_map *map);
int		ft_check_map(char *line);
int		ft_free_map(t_map *map);
int		ft_err(int err);
void		trash(t_map *map);
int		ft_ismapfil(t_map *map);
int		ft_proper(t_map *map, char **line, int fd);
void		*ft_ralloc(int *ptr, unsigned int size, int value);
#endif
