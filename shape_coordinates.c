/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:24:56 by iwithmor          #+#    #+#             */
/*   Updated: 2016/11/05 15:24:57 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	SHAPE_COORDINATES.C:
**		SAVES X & Y COORDINATES FOR BLOCKS OF A GIVEN SHAPE
*/

static void	store_coor(t_tetromino *piece, const char *x, const char *y)
{
	piece->x[0] = (int)(x[0] - '0');
	piece->x[1] = (int)(x[1] - '0');
	piece->x[2] = (int)(x[2] - '0');
	piece->x[3] = (int)(x[3] - '0');
	piece->y[0] = (int)(y[0] - '0');
	piece->y[1] = (int)(y[1] - '0');
	piece->y[2] = (int)(y[2] - '0');
	piece->y[3] = (int)(y[3] - '0');
}

void		straight_square_coordinates(t_tetromino *piece, int shape)
{
	if (shape == 1)
		store_coor(piece, "0000", "0123");
	else if (shape == 2)
		store_coor(piece, "0123", "0000");
	else if (shape == 3)
		store_coor(piece, "0101", "0011");
}

void		t_coordinates(t_tetromino *piece, int shape)
{
	if (shape == 4)
		store_coor(piece, "1012", "0111");
	else if (shape == 5)
		store_coor(piece, "0121", "0001");
	else if (shape == 6)
		store_coor(piece, "0010", "0112");
	else
		store_coor(piece, "1011", "0112");
}

void		z_coordinates(t_tetromino *piece, int shape)
{
	if (shape == 8)
		store_coor(piece, "0112", "0011");
	else if (shape == 9)
		store_coor(piece, "1201", "0011");
	else if (shape == 10)
		store_coor(piece, "0011", "0112");
	else
		store_coor(piece, "1010", "0112");
}

void		l_coordinates(t_tetromino *piece, int shape)
{
	if (shape == 12)
		store_coor(piece, "0001", "0122");
	else if (shape == 13)
		store_coor(piece, "1101", "0122");
	else if (shape == 14)
		store_coor(piece, "0100", "0012");
	else if (shape == 15)
		store_coor(piece, "0111", "0012");
	else if (shape == 16)
		store_coor(piece, "0012", "0111");
	else if (shape == 17)
		store_coor(piece, "2012", "0111");
	else if (shape == 18)
		store_coor(piece, "0120", "0001");
	else
		store_coor(piece, "0122", "0001");
}
