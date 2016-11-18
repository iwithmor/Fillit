/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:43:52 by iwithmor          #+#    #+#             */
/*   Updated: 2016/11/02 16:43:54 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	SHAPES.C
**		Returns a tetromino piece as an integer:
**		1	= STRAIGHT-vertical
**		2	= STRAIGHT-horizontal
**		3	= SQUARE
**		4	= T-up
**		5	= T-down
**		6	= T-right
**		7	= T-left
**		8	= Z-left
**		9	= Z-right
**		10	= Z-vertical_left
**		11	= Z-vertical_right
**		12	= L
**		13	= _|
**		14	= _
**			 |
**		15	= _
**			   |
**		16	= |___
**		17	= ___|
**		18	= ___
**			 |
**		19	= ___
**				 |
**		-1	= INVALID
*/

int	is_straight(int *arr)
{
	if (arr[1] - arr[0] == 5 && arr[2] - arr[1] == 5 && arr[3] - arr[2] == 5)
		return (1);
	if (arr[1] - arr[0] == 1 && arr[2] - arr[1] == 1 && arr[3] - arr[2] == 1)
		return (2);
	return (-1);
}

int	is_square(int *arr)
{
	if (arr[1] - arr[0] == 1 && arr[2] - arr[1] == 4 && arr[3] - arr[2] == 1)
		return (3);
	return (-1);
}

int	is_t(int *arr)
{
	if (arr[1] - arr[0] == 4 && arr[2] - arr[1] == 1 && arr[3] - arr[2] == 1)
		return (4);
	if (arr[1] - arr[0] == 1 && arr[2] - arr[1] == 1 && arr[3] - arr[2] == 4)
		return (5);
	if (arr[1] - arr[0] == 5 && arr[2] - arr[1] == 1 && arr[3] - arr[2] == 4)
		return (6);
	if (arr[1] - arr[0] == 4 && arr[2] - arr[1] == 1 && arr[3] - arr[2] == 5)
		return (7);
	return (-1);
}

int	is_z(int *arr)
{
	if (arr[1] - arr[0] == 1 && arr[2] - arr[1] == 5 && arr[3] - arr[2] == 1)
		return (8);
	if (arr[1] - arr[0] == 1 && arr[2] - arr[1] == 3 && arr[3] - arr[2] == 1)
		return (9);
	if (arr[1] - arr[0] == 5 && arr[2] - arr[1] == 1 && arr[3] - arr[2] == 5)
		return (10);
	if (arr[1] - arr[0] == 4 && arr[2] - arr[1] == 1 && arr[3] - arr[2] == 4)
		return (11);
	return (-1);
}

int	is_l(int *arr)
{
	if (arr[1] - arr[0] == 5 && arr[2] - arr[1] == 5 && arr[3] - arr[2] == 1)
		return (12);
	if (arr[1] - arr[0] == 5 && arr[2] - arr[1] == 4 && arr[3] - arr[2] == 1)
		return (13);
	if (arr[1] - arr[0] == 1 && arr[2] - arr[1] == 4 && arr[3] - arr[2] == 5)
		return (14);
	if (arr[1] - arr[0] == 1 && arr[2] - arr[1] == 5 && arr[3] - arr[2] == 5)
		return (15);
	if (arr[1] - arr[0] == 5 && arr[2] - arr[1] == 1 && arr[3] - arr[2] == 1)
		return (16);
	if (arr[1] - arr[0] == 3 && arr[2] - arr[1] == 1 && arr[3] - arr[2] == 1)
		return (17);
	if (arr[1] - arr[0] == 1 && arr[2] - arr[1] == 1 && arr[3] - arr[2] == 3)
		return (18);
	if (arr[1] - arr[0] == 1 && arr[2] - arr[1] == 1 && arr[3] - arr[2] == 5)
		return (19);
	return (-1);
}
