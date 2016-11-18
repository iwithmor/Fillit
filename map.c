/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 21:39:46 by iwithmor          #+#    #+#             */
/*   Updated: 2016/11/04 21:39:49 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	MAP.C
**		MAKE_MAP:	CREATES AN EMPTY MAP
**		PRINT_MAP:	PRINTS MAP
*/

int		map_size(t_tetromino *piece)
{
	int		len;
	int		size;

	len = ft_lstlen_counter(piece);
	size = 2;
	while (size * size < len * 4)
		++size;
	return (size);
}

char	**make_map(int size)
{
	char	**map;
	int		i;
	int		row;

	map = (char **)malloc(sizeof(char *) * (size + 1));
	if (!map)
		return (NULL);
	row = 0;
	while (row < size)
	{
		i = 0;
		map[row] = (char *)malloc(size + 1);
		if (!map[row])
			return (NULL);
		while (i < size)
		{
			map[row][i] = '.';
			++i;
		}
		map[row][i] = '\0';
		++row;
	}
	map[row] = NULL;
	return (map);
}

int		is_in_map(t_tetromino *piece, char **map, int mapsize)
{
	int		x;
	int		row;
	int		i;

	row = 0;
	i = 0;
	while (row < mapsize)
	{
		x = 0;
		while (x < mapsize)
		{
			if (piece->x[i] == x && piece->y[i] == row)
			{
				if (map[row][x] != '.')
					return (0);
				++i;
			}
			++x;
		}
		++row;
	}
	if (i < 4)
		return (0);
	return (1);
}

void	print_map(char **map, int size)
{
	int		i;
	int		row;

	row = 0;
	while (row < size)
	{
		i = 0;
		while (i < size)
			ft_putchar(map[row][i++]);
		ft_putchar('\n');
		++row;
	}
}
