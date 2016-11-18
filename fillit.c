/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 00:15:34 by iwithmor          #+#    #+#             */
/*   Updated: 2016/11/18 00:20:03 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**solve(char **map, t_tetromino *piece, int mapsize)
{
	int		column;
	int		row;
	char	**tmp;

	ft_putchar('\n');
	if (!piece)
		return (map);
	tmp = NULL;
	row = 0;
	while (row < mapsize)
	{
		column = 0;
		while (column < mapsize)
		{
			piece = move_coordinates(piece, column, row);
			if (is_in_map(piece, map, mapsize))
				tmp = solve(place(piece, map, mapsize), piece->next, mapsize);
			if (tmp)
				return (tmp);
			map = ft_remove(piece, map, mapsize);
			++column;
		}
		++row;
	}
	return (NULL);
}

void		fillit(t_tetromino *firstpiece)
{
	int		mapsize;
	char	**map;

	if (!firstpiece)
		return ;
	mapsize = map_size(firstpiece);
	map = NULL;
	while (!map)
	{
		map = make_map(mapsize);
		if (!(map = solve(map, firstpiece, mapsize)))
			++mapsize;
	}
	print_map(map, mapsize);
}
