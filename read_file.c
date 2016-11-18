/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 18:25:12 by iwithmor          #+#    #+#             */
/*   Updated: 2016/10/25 18:25:26 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	READ_FILE.C
**		Reads one tetromino at a time (21 bytes).
**	Calls:
**		validate_tetromino()
**		buf_concat()
*/

char	*read_file(int fd)
{
	char	buf[BUF_SIZE + 1];
	char	*filearray;
	int		bytesread;
	int		len;

	filearray = "";
	len = 0;
	while ((bytesread = read(fd, buf, BUF_SIZE)) > 0)
	{
		if (buf[0] != '.' && buf[0] != '#')
			return (NULL);
		len += bytesread;
		if (len > MAX_SIZE)
			return (NULL);
		if (bytesread < BUF_SIZE - 1)
			return (NULL);
		buf[bytesread] = '\0';
		if (!validate_tetromino(buf))
			return (NULL);
		filearray = buf_concat(filearray, buf);
	}
	return (filearray);
}
