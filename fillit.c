/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 12:47:04 by ahrytsen          #+#    #+#             */
/*   Updated: 2017/11/24 20:27:36 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

inline static void	ft_switch_figure(t_etr *figures, t_16bit *map)
{
	*(t_64bit*)(map + figures->y) ^= figures->value >> figures->x;
}

inline static int	ft_try_to_fill(t_etr *figures, t_16bit *map)
{
	return (!(*(t_64bit*)(map + figures->y) & (figures->value >> figures->x)));
}

int					ft_solve(t_etr *figures, t_16bit *map, int sqr_size)
{
	if (!figures->id)
		return (1);
	figures->y = figures->prev ? figures->prev->y : 0;
	figures->x = figures->prev ? figures->prev->x : 0;
	while (figures->y + figures->h <= sqr_size)
	{
		while (figures->x + figures->w <= sqr_size)
		{
			if (ft_try_to_fill(figures, map))
			{
				ft_switch_figure(figures, map);
				if (ft_solve(figures + 1, map, sqr_size))
					return (1);
				ft_switch_figure(figures, map);
			}
			figures->x++;
		}
		figures->x = 0;
		figures->y++;
	}
	figures->x = 0;
	figures->y = 0;
	return (0);
}
