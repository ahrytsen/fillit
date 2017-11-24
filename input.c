/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:02:36 by ahrytsen          #+#    #+#             */
/*   Updated: 2017/11/24 21:07:13 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_validate(char *tetr)
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

static t_64bit	ft_getvalue(char **tetr)
{
	t_64bit	value;
	int		i;
	int		j;
	t_64bit	mask;

	if (!tetr)
		ft_error();
	mask = ~0L;
	value = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (tetr[i][j] == '#')
				value |= (1L << (16 * (i + 1) - 1 - j));
	}
	while (!(value & (mask >> 48)))
		value >>= 16;
	mask = (1L << 63) | (1L << 47) | (1L << 31) | (1L << 15);
	while (!(value & mask))
		value <<= 1;
	while (i--)
		free(tetr[i]);
	free(tetr);
	return (value);
}

static void		ft_figure_set(char id, t_64bit value, t_etr *figure)
{
	int		h;
	int		w;
	t_64bit	mask;

	h = 0;
	w = 0;
	mask = ~0L;
	mask >>= 48;
	while ((value & (mask << (16 * h))) && h < 4)
		h++;
	mask = (1L << 63) | (1L << 47) | (1L << 31) | (1L << 15);
	while ((value & (mask >> w)) && w < 4)
		w++;
	figure->id = id + 'A';
	figure->h = h;
	figure->w = w;
	figure->value = value;
	while (id && figure->value != (figure - id)->value)
		id--;
	if (id)
		figure->prev = (figure - id);
}

int				ft_reader(const int fd, t_etr *figures)
{
	char	tmp[22];
	int		count[2];
	int		i;

	i = 0;
	ft_bzero(tmp, 22);
	while ((count[0] = read(fd, tmp, 21)))
	{
		(i > 25 || count[0] < 20) ? ft_error() : ft_validate(tmp);
		ft_figure_set(i, ft_getvalue(ft_strsplit(tmp, '\n')), figures + i);
		ft_bzero(tmp, 22);
		count[1] = count[0];
		i++;
	}
	if (close(fd) || !i || count[1] != 20)
		ft_error();
	return (i);
}
