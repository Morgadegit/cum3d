#ifndef CUB3D_H
# define CUB3D_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"

typedef	struct	s_map
{
	int	res[2];
	char	*txtr[5];
	int	floor[3];
	int	ceiling[3];
	int	*map;
}		t_map;
void	ft_init_map(t_map *map);
int	ft_check_line(int state, char *line, int fd);
#endif
