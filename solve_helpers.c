/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:33:21 by iwithmor          #+#    #+#             */
/*   Updated: 2016/11/06 16:33:23 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetromino	*move_coordinates(t_tetromino *piece, int x, int y)
{
	int		xmin;
	int		ymin;
	int		i;

	xmin = 200;
	ymin = 200;
	i = 0;
	while (i < 4)
	{
		xmin = (piece->x[i] < xmin) ? piece->x[i] : xmin;
		ymin = (piece->y[i] < ymin) ? piece->y[i] : ymin;
		++i;
	}
	i = 0;
	while (i < 4)
	{
		piece->x[i] = piece->x[i] - xmin + x;
		piece->y[i] = piece->y[i] - ymin + y;
		++i;
	}
	return (piece);
}

char		**place(t_tetromino *piece, char **map, int mapsize)
{
	int		column;
	int		row;
	int		i;

	row = 0;
	i = 0;
	while (row < mapsize)
	{
		column = 0;
		while (column < mapsize)
		{
			if (piece->x[i] == column && piece->y[i] == row)
			{
				map[row][column] = piece->letter;
				++i;
			}
			++column;
		}
		++row;
	}
	map[row] = NULL;
	return (map);
}

char		**ft_remove(t_tetromino *piece, char **map, int mapsize)
{
	int		column;
	int		row;

	row = 0;
	while (row < mapsize)
	{
		column = 0;
		while (column < mapsize)
		{
			if (map[row][column] == piece->letter)
				map[row][column] = '.';
			++column;
		}
		++row;
	}
	return (map);
}
