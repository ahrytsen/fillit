/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:02:36 by ahrytsen          #+#    #+#             */
/*   Updated: 2017/11/19 21:12:36 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_validate(char **tetr)
{
	int		i;
	int		j;
	int		conects;

	conects = 0;
	i = 0;
	while (tetr[i])
	{
		j = 0;
		while (tetr[i][j] && (tetr[i][j] == '.' || tetr[i][j] == '#'))
			if (tetr[i][j] == '#')
			{
				conects += (i < 3 && tetr[i + 1][j] == '#') ? 1 : 0;
				conects += (tetr[i][j + 1] == '#') ? 1 : 0;
				conects += (i > 0 && tetr[i - 1][j] == '#') ? 1 : 0;
				conects += (j > 0 && tetr[i][j - 1] == '#') ? 1 : 0;
				j++;
			}
			else
				(tetr[i][j] != '.') ? ft_error() : j++;
		(j != 4) ? ft_error() : i++;
	}
	(i != 4 || (conects != 6 && conects != 8)) ? ft_error() : 0;
}

/*
** void	ft_push_combs(char id, t_64bit value, t_map *matrix)
** {
** }
*/

int		ft_reader(int fd, t_map *matrix)
{
	char	**tetrimino;
	char	tmp[22];
	t_64bit	value;
	int		count;
	int		i;

	i = 0;
	ft_bzero(tmp, 22);
	matrix = NULL;
	value = 0;
	while ((count = read(fd, tmp, 21)))
	{
		if (count < 20 || i++ > 25
			|| !(tetrimino = ft_strsplit(tmp, '\n')))
			ft_error();
		ft_validate(tetrimino);
		free(tetrimino);
		ft_bzero(tmp, 22);
	}
	if (close(fd))
		ft_error();
	return (0);
}
