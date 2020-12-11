#include "cub3d.h"

static void	ft_draw_txtr(t_mega *mega, t_eng *eng, t_txtr *txtr, int x)
{
	unsigned int	*pix;
	int		y;
	double		WallH;

	y = eng->Wmin;
	WallH = eng->side < 2 ? eng->pos[1] + eng->Wdist * eng->ray[1] : eng->pos[0] + eng->Wdist * eng->ray[0];
	txtr->y = 0;
	txtr->x = WallH == floor(WallH) ? 0 : txtr->w * (WallH - floor(WallH));
	txtr->step = 1 + ((eng->Wmax - eng->Wmin) / txtr->h);
	while (y < eng->Wmax)
	{
		if ((y - eng->Wmin) % txtr->step == 0)
			txtr->y++;
		pix = (int *)(txtr->data + (txtr->y * txtr->sline) + (txtr->x * 4));
		mlx_pixel_put(mega->mlxp, mega->win, x, y, *pix);
		y++;
	}
//	if (x == mega->map.res[0] / 2)
//		printf("%i -- %i -- %i\n", x, repeat, txtr->step);
}

static void	ft_draw_screen(t_mega *mega, t_eng *eng, int x)
{
	int	y;

	y = mega->map.res[1];
	while (y-- > eng->Wmax)
		mlx_pixel_put(mega->mlxp, mega->win, x, y, ft_get_color(mega->map.ceiling));
	y += 2;
//	while (y-- > eng->Wmin - 1)
//		mlx_pixel_put(mega->mlxp, mega->win, x, y - 1, 0x9C4E97 / (eng->side + 1));
	y = eng->Wmin;
	while (y-- > 0)
		mlx_pixel_put(mega->mlxp, mega->win, x, y - 2, ft_get_color(mega->map.floor));
	ft_draw_txtr(mega, eng, &mega->map.ttr[eng->side], x);
}

void	ft_draw_wall(t_eng *eng, t_map *map, t_mega *mega, int x)
{
	int	Wheight;

	Wheight = (int)(map->res[1] / eng->Wdist);
	eng->Wmin = (-1 * Wheight) / 2 + map->res[1] / 2;
	eng->Wmin < 0 ? eng->Wmin = 0 : 0;
	eng->Wmax = Wheight / 2 + map->res[1] / 2;
	eng->Wmax >= map->res[1] ? eng->Wmax = map->res[1] - 1 : 0;
	ft_draw_screen(mega, eng, x);
}

