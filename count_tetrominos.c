/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_tetrominos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 00:13:36 by iwithmor          #+#    #+#             */
/*   Updated: 2016/10/29 00:13:40 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	COUNT_TETROMINOS.C
**		Counts the amount of tetrominos in a file
*/

int	count_tetrominos(char *filearray)
{
	int	count;

	count = 0;
	while (*filearray != '\0')
	{
		if (*filearray == '\n')
			++filearray;
		if (*filearray != '.' && *filearray != '#')
			return (0);
		++count;
		filearray += 20;
	}
	return (count);
}
