/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 23:24:05 by iwithmor          #+#    #+#             */
/*   Updated: 2016/10/27 23:24:07 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	STORE_DATA.C
**		Stores tetromino pieces as an array of integers.
**	Calls:
**		count_tetrominos()
**		tetromino_type()
**		link_data()
*/

int	*store_data(char *filearray)
{
	int *data;
	int	*datacpy;
	int	tetrocount;
	int i;

	if (!filearray)
		return (NULL);
	tetrocount = count_tetrominos(filearray);
	if (tetrocount == 0)
		return (NULL);
	data = (int *)malloc(tetrocount + 1);
	if (!data)
		return (NULL);
	datacpy = data;
	i = -1;
	while (++i < tetrocount && filearray)
	{
		*data = tetromino_type(filearray);
		if (*data < 0)
			return (NULL);
		filearray += 21;
		++data;
	}
	*data = -1;
	return (datacpy);
}
