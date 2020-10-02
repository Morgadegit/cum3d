/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 18:02:57 by sraphard          #+#    #+#             */
/*   Updated: 2020/10/01 14:17:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"

# define ESC	0xff1b
# define LEFT	0xff51

typedef	struct	s_map
{
	int	res[2];
	char	*txtr[5];
	int	floor[3];
	int	ceiling[3];
	char	**map;
}		t_map;
typedef struct	s_eng
{
	double	pos[2];
	double	dir[2];
	double	cam[2];
	double	turn;
	double	step;
	double	scr;
	double	ray[2];
	int	Dpos[2];
	double	Ddist[2];
	double	Ddelta[2];
	int	Dstep[2];
	int	Wdir;
	double	Wdist;
	int	side;
}		t_eng;
typedef struct	s_mega
{
	t_map	map;
	t_eng	eng;
	void	*mlxp;
	void	*win;
}		t_mega;
int		ft_map_parse(t_map *map, char *cub);
void		ft_init_map(t_map *map);
int		ft_check_map(char *line);
int		ft_free_map(t_map *map);
int		ft_err(int err);
void		trash(t_map *map);
int		ft_ismapfil(t_map *map);
int		ft_proper(t_map *map, char **line, int fd);
char		**ft_ralloc(char **ptr, int size);
int		ft_exit(t_mega *mega, int code);
void		ft_get_start(t_mega *mega);
void		ft_raycast(t_mega *mega, t_eng *eng, t_map *map, int x);
int		ft_get_color(int rgb[3]);
#endif
