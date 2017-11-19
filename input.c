/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:02:36 by ahrytsen          #+#    #+#             */
/*   Updated: 2017/11/19 17:07:04 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_getvalue()
{

}

void	ft_reader(int fd, t_map *matrix)
{
	char    **tetrimino;
    char    tmp[22];
    int     count;
    int     i;

    i = 0;
    ft_bzero(tmp, 22);
    while ((count = read(fd, tmp, 21)))
    {
        if ((count != 20 && count != 21) || i++ > 25
            || !(tetrimino = ft_strsplit(tmp, '\n'))
            || !ft_lstpush_back(tetriminos, tetrimino, 5 * sizeof(char*)))
            ft_error();
        free(tetrimino);
        ft_bzero(tmp, 22);
    }
    if (!*tetriminos || close(fd))
        ft_error();
}
