/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:51:42 by iwithmor          #+#    #+#             */
/*   Updated: 2016/11/05 14:51:45 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	LINK_DATA.C:
**		CREATE A LINKED LIST OF TETROMINOS
**	CALLS:
**		add_coordinates():
**			straight_coordinates()
**			square_coordinates()
**			t_coordinates()
**			z_coordinates()
**			l_coordinates()
*/

static void		add_coordinates(t_tetromino *piece, int shape)
{
	piece->x = (int *)malloc(sizeof(int) * 4);
	piece->y = (int *)malloc(sizeof(int) * 4);
	if (shape >= 1 && shape <= 3)
		straight_square_coordinates(piece, shape);
	else if (shape >= 4 && shape <= 7)
		t_coordinates(piece, shape);
	else if (shape >= 8 && shape <= 11)
		z_coordinates(piece, shape);
	else if (shape >= 12 && shape <= 19)
		l_coordinates(piece, shape);
	else
		piece = NULL;
}

t_tetromino		*link_data(int *arr)
{
	int			i;
	t_tetromino	*first;
	t_tetromino	*tmp;

	i = 0;
	first = (t_tetromino *)malloc(sizeof(t_tetromino));
	if (!first)
		return (NULL);
	tmp = first;
	while (arr[i] > 0)
	{
		tmp->letter = 'A' + i;
		add_coordinates(tmp, arr[i]);
		if (!tmp)
			return (NULL);
		if (arr[i + 1] > 0)
		{
			tmp->next = (t_tetromino *)malloc(sizeof(t_tetromino));
			if (!tmp->next)
				return (NULL);
			tmp = tmp->next;
		}
		++i;
	}
	return (first);
}
