/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:02:36 by ahrytsen          #+#    #+#             */
/*   Updated: 2017/11/19 18:06:59 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_getvalue()
{

}

void	ft_push_combs(char id, t_64bit value, t_map *matrix)
{
}
int		ft_reader(int fd, t_map *matrix)
{
	char    **tetrimino;
    char    tmp[22];
    int     count;
    int     i;

    i = 0;
    ft_bzero(tmp, 22);
    while ((count = read(fd, tmp, 21)))
    {
        if (count < 20 || i++ > 25
            || !(tetrimino = ft_strsplit(tmp, '\n')))
			ft_error();

        free(tetrimino);
        ft_bzero(tmp, 22);
    }
    if (!*tetriminos || close(fd))
        ft_error();
}
