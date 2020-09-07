/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 19:19:42 by sraphard          #+#    #+#             */
/*   Updated: 2020/09/07 13:48:30 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_r(char *line, int i, int sstate)
{
	while (line[++i])
		if (ft_is_set_nbr(sstate, 3, 1, 3, 5) && ft_iswhite(line[i]))
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
	return (1);
}

static int	ft_check_txt(char *line, int i, int sstate)
{
	while (line[++i])
		if ((sstate == 1 || sstate == 3) && ft_iswhite(line[i]))
		{
			while (ft_iswhite(line[i]) && line[i])
				i++;
			i++;
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

static int	ft_chck_clr(char *line, int i, int sstate)
{
	while (line[++i])
		if (sstate == 1 || sstate == 7)
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

int		ft_check_map(char *line, int fd)
{
	static char	*check_repeat = "";

	if (ft_strlen(check_repeat) == 32)
		return (1);
	if (ft_strlstr(check_repeat, line, 2))
	{
		printf("%s\n", check_repeat);
		ft_putstr_fd("Error\nRepeating Map Parameters.", 2);
		return (0);
	}
	check_repeat = ft_strnjoin(check_repeat, line, 2, 10);
	check_repeat = ft_strjoin(check_repeat, ", ", 10);
	if (*line == 'R')
		return (ft_check_r(line, 0, 1));
	else if (!ft_strncmp(line, "NO", 2) || !ft_strncmp(line, "SO", 2) ||
	!ft_strncmp(line, "WE", 2) || !ft_strncmp(line, "EA", 2))
		return (ft_check_txt(line, 1, 1));
	else if (*line == 'S')
		return (ft_check_txt(line, 0, 1));
	else if (*line == 'F' || *line == 'C')
		return (ft_chck_clr(line, 0, 1));
	return (1);
}
