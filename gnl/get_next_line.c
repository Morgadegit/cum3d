/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:26:15 by sraphard          #+#    #+#             */
/*   Updated: 2020/01/16 15:46:41 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

#define BUFFER_SIZE 24

static char	*actual_gnl(char *buf_nd, int fd, int *size)
{
	char		buf_st[BUFFER_SIZE + 1];

	while (!ft_strchr(buf_nd, '\n'))
	{
		if ((*size = read(fd, buf_st, BUFFER_SIZE)) == -1)
			return (0);
		buf_st[*size] = 0;
		if (*size < 1)
		{
			if (*buf_nd > 0)
				break ;
			free(buf_nd);
			return (ft_strdup(""));
		}
		buf_nd = ft_strjoin(buf_nd, buf_st, 'x');
	}
	return (buf_nd);
}

int			get_next_line(int fd, char **line)
{
	char		*buf_nd;
	static char	*buff_def = NULL;
	int			size;

	size = 1;
	if (BUFFER_SIZE < 1 || !(&(*line)))
		return (-1);
	if (!(buf_nd = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
	*buf_nd = 0;
	if (buff_def)
	ft_strlcpy(buf_nd, buff_def, BUFFER_SIZE);
	if (!(buf_nd = actual_gnl(buf_nd, fd, &size)))
	{
		*line = ft_strdup("");
		return (-1);
	}
	free(buff_def);
	buff_def = ft_strchr(buf_nd, '\n');
	if (buff_def)
	{
		*buff_def = 0;
		buff_def = ft_strdup(buff_def + 1);
	}
	*line = buf_nd;
	return (size > 0 ? 1 : size);
}
