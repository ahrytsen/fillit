/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:02:36 by ahrytsen          #+#    #+#             */
/*   Updated: 2017/11/23 18:47:28 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_validate(const char *tetr)
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

static t_64bit	ft_getvalue(const char **tetr)
{
	t_64bit	value;
	int		i;
	t_64bit	mask;

	if (!tetr)
		ft_error();
	mask = 0;
	value = 0;
	i = -1;
	while (++i < 16)
		if (tetr[i / 4][i % 4] == '#')
			value |= 1L << (63 - 16 * (i / 4) - (i % 4));
	while (!(value & ~(~mask >> 16)))
		value <<= 15;
	mask = (1L << 63) | (1L << 47) | (1L << 31) | (1L << 15);
	while (!(value & mask))
		value <<= 1;
	return (value);
}

static void	ft_figure_set(char id, t_64bit value, t_etr *figure)
{
	int		h;
	int		w;
	t_64bit	mask;

	h = 0;
	w = 0;
	mask = 0;
	mask = ~(~mask >> 16);
	while ((value & (mask >> 16 * h)) && h < 4)
		h++;
	mask = (1L << 63) | (1L << 47) | (1L << 31) | (1L << 15);
	while ((value & (mask >> w)) && w < 4)
		w++;
	figure->id = id + 'A';
	figure->h = h;
	figure->w = w;
	figure->value = value;
	while (id)
	{
		if (figure->value == (figure - id)->value)
			figure->prew = figure - id;
		id--;
	}
}

int		ft_reader(const int fd, t_etr *figures)
{
	char	tmp[22];
	t_64bit	value;
	int		count[2];
	int		i;

	i = 0;
	ft_bzero(tmp, 22);
	value = 0;
	while ((count[0] = read(fd, tmp, 21)))
	{
		(i > 25 || count[0] < 20) ? ft_error() : ft_validate(tmp);
		value = ft_getvalue((const char**)ft_strsplit(tmp, '\n'));
		ft_figure_set(i, value, figures + i);
		ft_bzero(tmp, 22);
		count[1] = count[0];
		i++;
	}
	if (close(fd) || !i || count[1] != 20)
		ft_error();
	return (i);
}
