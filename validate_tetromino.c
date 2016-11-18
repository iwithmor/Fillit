/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_tetromino.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 00:45:43 by iwithmor          #+#    #+#             */
/*   Updated: 2016/10/31 00:45:48 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	HASHTAG_ABC.C
**		Converts hashtags to letters
*/

char	*validate_tetromino(char *buf)
{
	int i;
	int blocks;

	i = -1;
	blocks = 0;
	while (buf[++i] != '\0')
	{
		if (i == 4 || i == 9 || i == 14 || i == 19 || i == 20)
		{
			if (buf[i] != '\n')
				return (NULL);
		}
		else if (buf[i] != '.' && buf[i] != '#')
			return (NULL);
		if (buf[i] == '#')
			++blocks;
	}
	if (blocks != 4)
		return (NULL);
	return (buf);
}
