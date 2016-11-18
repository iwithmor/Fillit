/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetromino_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:50:04 by iwithmor          #+#    #+#             */
/*   Updated: 2016/10/31 15:50:06 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	TETROMINO_TYPE.C
**		Returns a tetromino piece as an integer.
**		STRAIGHT	= 1, 2
**		SQUARE 		= 3
**		T			= 4, 5, 6, 7
**		Z			= 8, 9, 10, 11
**		L			= 12, 13, 14, 15, 16, 17, 18, 19
**		INVALID		= -1
**
**	Calls:
**		get_shape():
**			is_straight()
**			is_square()
**			is_t()
**			is_z()
**			is_l()
*/

static int	get_shape(int *arr)
{
	int	result;

	result = is_straight(arr);
	result = (result > 0) ? result : is_square(arr);
	result = (result > 0) ? result : is_t(arr);
	result = (result > 0) ? result : is_z(arr);
	result = (result > 0) ? result : is_l(arr);
	result = (result > 0) ? result : -1;
	return (result);
}

int			tetromino_type(char *str)
{
	int *arr;
	int i;
	int j;

	i = 0;
	j = 0;
	arr = (int *)malloc(sizeof(int) * 4 + 1);
	if (!arr)
		return (-1);
	while (i < 20)
	{
		if (str[i] == '#')
			arr[j++] = i;
		++i;
	}
	while (j < 4)
		arr[j++] = -1;
	return (get_shape(arr));
}
