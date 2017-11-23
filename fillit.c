/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:47:04 by ahrytsen          #+#    #+#             */
/*   Updated: 2017/11/23 16:01:40 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

inline static void		ft_switch_figure(t_etr *figures, t_16bit *map)
{
	*(t_64bit*)(map + figures->y) ^= figures->value >> figures->x;
}

inline static t_64bit	ft_try_to_fill(t_etr *figures, t_16bit *map)
{
	return (*(t_64bit*)(map + figures->y) & (figures->value >> figures->x));
}

int						ft_solve(t_etr *figures, t_16bit *map, int sqr_size)
{
//	int tmp;

	if (!figures->id)
		return (1);
//	tmp = figures->prew ? 
//		(figures->prew->x + figures->prew->y * sqr_size) : 0;
	figures->y = 0;//tmp / sqr_size;
	while (figures->y + figures->h <= sqr_size)
	{
		figures->x = 0;//(figures->y == tmp / sqr_size ? tmp % sqr_size : 0);
		while (figures->x + figures->w <= sqr_size)
		{
			if (!ft_try_to_fill(figures, map))
			{
				ft_switch_figure(figures, map);
				if (ft_solve(figures + 1, map, sqr_size))
					return (1);
				ft_switch_figure(figures, map);
			}
			figures->x++;
		}
		figures->y++;
	}
	figures->x = 0;
	figures->y = 0;
	return (0);
}
