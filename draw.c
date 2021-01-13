#include "cub3d.h"

static void	ft_draw_txtr(t_mega *mega, t_eng *eng, t_txtr *txtr, int x)
{
	unsigned int	*pix;
	int		y;
	double		WallH;
	double		wall;

	y = eng->Wmin;
	wall = eng->Wmax - eng->Wmin;
	WallH = eng->side < 2 ? eng->pos[1] + eng->Wdist * eng->ray[1] : eng->pos[0] + eng->Wdist * eng->ray[0];
	txtr->y = 0;
	txtr->x = WallH == floor(WallH) ? 0 : txtr->w * (WallH - floor(WallH));
	while (y < eng->Wmax)
	{
		txtr->y = ((wall / 2.0) - (mega->map.res[1] / 2.0) + y) * (txtr->h / wall);
		txtr->y < 0 ? txtr->y = 0 : 0 ;
		pix = (int *)(txtr->data + (txtr->y * txtr->sline) + (txtr->x * 4));
		eng->render[y * mega->map.res[0] + x] = *pix; 
		y++;
	}
}

static void	ft_draw_screen(t_mega *mega, t_eng *eng, t_map *map, int x)
{
	int	y;

	y = mega->map.res[1];
	while (y-- > eng->Wmax)
		eng->render[y * map->res[0] + x] = ft_get_color(mega->map.ceiling);
	y += 2;
	y = eng->Wmin;
	while (y-- > 0)
		eng->render[y * map->res[0] + x] = ft_get_color(mega->map.floor);
	ft_draw_txtr(mega, eng, &mega->map.ttr[eng->side], x);
	mlx_put_image_to_window(mega->mlxp, mega->win, eng->image, 0, 0);
}

void	ft_draw_wall(t_eng *eng, t_map *map, t_mega *mega, int x)
{
	int	Wheight;

	Wheight = (int)(map->res[1] / eng->Wdist);
	eng->Wmin = (-1 * Wheight) / 2 + map->res[1] / 2;
	eng->Wmin < 0 ? eng->Wmin = 0 : 0;
	eng->Wmax = Wheight / 2 + map->res[1] / 2;
	eng->Wmax >= map->res[1] ? eng->Wmax = map->res[1] - 1 : 0;
	ft_draw_screen(mega, eng, map, x);
}

