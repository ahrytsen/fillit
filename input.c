/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:02:36 by ahrytsen          #+#    #+#             */
/*   Updated: 2017/11/21 16:40:38 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_validate(char *tetr)
{
	int		i;
	int		conects;
	int		sharps;

	conects = 0;
	i = 0;
	sharps = 0;
	while (i < 20)
	{
		if (tetr[i] == '#' && (i + 1) % 5 && sharps++ < 4)
		{
			conects += (i > 0 && tetr[i - 1] == '#') ? 1 : 0;
			conects += (tetr[i + 1] == '#') ? 1 : 0;
			conects += (i > 4 && tetr[i - 5] == '#') ? 1 : 0;
			conects += (i < 14 && tetr[i + 5] == '#') ? 1 : 0;
		}
		else if (((i + 1) % 5 && tetr[i] != '.')
				|| (!(i + 1) % 5 && tetr[i] != '\n'))
			ft_error();
		i++;
	}
	if ((tetr[i] && tetr[i] != '\n') || (conects != 6 && conects != 8))
		ft_error();
}

t_64bit	ft_getvalue(char **tetr)
{
	t_64bit	value;
	int		i;

	if (!tetr)
		ft_error();
	value = 0;
	i = 0;
	while (i < 16)
	{
		if (i && tetr[i / 4][i % 4] == '#')
			value |= 1L << (63 - 16 * (i / 4) - (i % 4));
		else if (!i && tetr[0][0] == '#')
			value |= 1L << 63;
		i++;
	}
	while (((t_16bit)vallue)[0] == 0)
		value <<= 16;
	return (value);
}

/*
** void	ft_push_combs(char id, t_64bit value, t_map *matrix)
** {
** }
*/

int		ft_reader(int fd, t_map *matrix)
{
	char	tmp[22];
	t_64bit	value;
	int		count[2];
	int		i;

	i = 0;
	ft_bzero(tmp, 22);
	matrix = NULL;
	value = 0;
	while ((count[0] = read(fd, tmp, 21)))
	{
		(i++ > 25 || count[0] < 20) ? ft_error() : ft_validate(tmp);
		value = ft_getvalue(ft_strsplit(tmp, '\n'));
		ft_bzero(tmp, 22);
		count[1] = count[0];
	}
	if (close(fd) || !i || count[1] != 20)
		ft_error();
	return (i);
}
