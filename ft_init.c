#include "cub3d.h"

static t_txtr	ft_init_txtr(t_txtr *ttr)
{
	ttr->path = NULL;
	ttr->addr = NULL;
	ttr->data = NULL;
	ttr->h = 0;
	ttr->w = 0;
	ttr->bpp = -1;
	ttr->sline = -1;
	ttr->endian = -1;
	ttr->x = 0;
	ttr->y = 0;
	ttr->step = 0;
}

void		ft_init_map(t_map *map)
{
	int	i;

	map->ttr = malloc(sizeof(t_txtr) * 5);
	i = -1;
	while (++i < 5)
		ft_init_txtr(&map->ttr[i]);
	i = -1;
	map->res[0] = -1;
	map->res[1] = -1;
	while (++i < 5)
		map->txtr[i] = ft_strdup("");
	i = -1;
	while (++i < 3)
		map->floor[i] = -1;
	i = -1;
	while (++i < 3)
		map->ceiling[i] = -1;
	map->map = malloc(sizeof(char *));
	map->map[0] = ft_strdup("");
}

void		ft_init_mega(t_mega *mega)
{
	ft_init_map(&(mega->map));
	mega->mlxp = NULL;
	mega->win = NULL;
	mega->pid = -1;
}
