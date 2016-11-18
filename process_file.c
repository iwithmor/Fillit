/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 17:06:25 by iwithmor          #+#    #+#             */
/*   Updated: 2016/10/25 17:06:27 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	PROCESS_FILE.C
**		Open and close a file.
**	Calls:
**		store_data()
**		read_file()
*/

t_tetromino	*process_file(char *filename)
{
	int		fd;
	int		*data;

	data = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() error\n");
		return (NULL);
	}
	data = store_data(read_file(fd));
	if (close(fd) == -1)
		ft_putstr("close() error\n");
	if (!data)
	{
		ft_putstr("error\n");
		return (NULL);
	}
	return (link_data(data));
}
