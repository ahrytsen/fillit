/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skushnir <skushnir@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 16:43:40 by skushnir          #+#    #+#             */
/*   Updated: 2017/11/24 20:44:18 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_fill_sqr(char **square, t_etr *figures)
{
	int		x;
	int		y;
	t_16bit	tmp[4];

	y = figures->y;
	ft_bzero(tmp, sizeof(t_16bit) * 4);
	*(t_64bit*)tmp |= figures->value;
	while (y < (figures->y + figures->h))
	{
		x = figures->x;
		while (x < (figures->x + figures->w))
		{
			if (tmp[y - figures->y] & (1 << (15 - (x - figures->x))))
				square[y][x] = figures->id;
			x++;
		}
		y++;
	}
}

void		ft_output(t_etr *figures, int size)
{
	int		i;
	char	**square;

	if (!(square = (char**)ft_memalloc(sizeof(char*) * (size + 1))))
		ft_error();
	i = 0;
	while (i < size)
		if (!(square[i++] = (char*)ft_memalloc(sizeof(char) * (size + 1))))
			ft_error();
	i = 0;
	while (i < size)
		ft_memset(square[i++], '.', size);
	while (figures->id)
		ft_fill_sqr(square, figures++);
	while (*square)
		ft_putendl(*square++);
}
