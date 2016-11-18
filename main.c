/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:09:38 by iwithmor          #+#    #+#             */
/*   Updated: 2016/10/20 19:09:45 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	MAIN.C
**		Verify correct user input.
**	Calls:
**		fillit()
**		process_file()
*/

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		fillit(process_file(argv[1]));
		return (0);
	}
	ft_putstr("usage:	./fillit source_file");
	return (1);
}
