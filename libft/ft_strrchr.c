/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraphard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:50:16 by sraphard          #+#    #+#             */
/*   Updated: 2019/10/18 21:09:44 by sraphard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	test;
	char			*locate;
	int				i;

	test = (unsigned char)c;
	locate = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == test)
			locate = (&((char*)s)[i]);
		i++;
	}
	if (test == 0)
		return (&((char*)s)[i]);
	else if (locate)
		return (locate);
	else
		return (0);
}
