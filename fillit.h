/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahrytsen <ahrytsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:26:53 by ahrytsen          #+#    #+#             */
/*   Updated: 2017/11/19 18:06:56 by ahrytsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef unsigned short	t_16bit;
typedef	unsigned long	t_64bit;
typedef struct s_map	t_map;

struct					s_map
{
	char	id;
	bit16	map[16];
	t_map	*next;
	t_map	*prew;
};

void					ft_error();
void					ft_usage();
int						ft_reader(int fd, t_map *matrix);
void					ft_output(t_map map, int size);

#endif
