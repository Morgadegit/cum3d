/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:19:42 by sraphard          #+#    #+#             */
/*   Updated: 2020/09/06 15:42:01 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_r(char *line, int i, int sstate)
{
	while (line[++i])
	{
		if (sstate == 0 && line[i] == 'R')
			sstate++;
		else if (ft_is_set_nbr(sstate, 3, 1, 3, 5) && ft_iswhite(line[i]))
		{
			while (ft_iswhite(line[i]))
				i++;
			i--;
			sstate++;
		}
		else if ((sstate == 2 || sstate == 4) && ft_isdigit(line[i]))
		{
			while (ft_isdigit(line[i]))
				i++;
			i--;
			sstate++;
		}
		else
		{
			ft_putstr_fd("Error\nInvalid Resolution.", 2);
			return (0);
		}
	}
	return (1);
}

static int	ft_check_txt(char *line, int i, int sstate, int state)
{
	while (line[++i])
		if (sstate == 0 && ((state == 1 && !ft_strncmp(line, "NO", 2))
		|| (state == 2 && !ft_strncmp(line, "SO", 2)) || (state == 3 &&
		!ft_strncmp(line, "WE", 2)) || (state == 4 &&
		!ft_strncmp(line, "EA", 2))))
		{
			i++;
			sstate++;
		}
		else if (sstate == 0 && (state == 5 && *line == 'S'))
			sstate++;
		else if ((sstate == 1 || sstate == 3) && ft_iswhite(line[i]))
		{
			while (ft_iswhite(line[i]) && line[i])
				i++;
			i--;
			sstate++;
		}
		else if (sstate == 2 &&
				open(ft_strtrim(line + i, " \t"), O_RDONLY) != -1)
		{
			i += ft_strlen(ft_strtrim(line + i, " \t")) - 1;
			sstate++;
		}
		else
		{
			ft_putstr_fd("Error\nInvalid Texture.", 2);
			return (0);
		}
	return (1);
}

static int	ft_err_clr(int *sstate, int check, char **line, int *i)
{
	if (ft_is_set_nbr(*sstate, 3, 2, 4, 6) &&
		ft_is_btwn((check = atoi(*line + *i)), 0, 255))
	{
		*i += ft_nbrlen(check) - 1;
		(*sstate)++;
		return (1);
	}
	else
	{
		ft_putstr_fd("Error\nInvalid Colour.", 2);
		return (0);
	}
}

static int	ft_chck_clr(char *line, int i, int sstate, int state)
{
	while (line[++i])
		if (sstate == 0 &&
		((state == 6 && *line == 'F') || (state == 7 && *line == 'C')))
			sstate++;
		else if (sstate == 1 || sstate == 7)
		{
			while (ft_iswhite(line[i]) && line[i])
				i++;
			i--;
			sstate++;
		}
		else if (ft_is_set_nbr(sstate, 3, 2, 4, 6))
		{
			if (!ft_err_clr(&sstate, 0, &line, &i))
				return (0);
		}
		else if (ft_is_set_nbr(sstate, 2, 3, 5) && line[i] == ',')
			sstate++;
		else
			return (ft_err_clr(&sstate, 0, &line, &i));
	return (1);
}

int		ft_check_line(int state, char *line, int fd)
{
	if (state == 0)
		return (ft_check_r(line, -1, 0));
	else if (state >= 1 && state <= 5)
		return (ft_check_txt(line, -1, 0, state));
	else if (state == 6 || state == 7)
		return (ft_chck_clr(line, -1, 0, state));
	return (1);
}
