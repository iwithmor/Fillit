/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen_counter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrobinso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 00:07:33 by mrobinso          #+#    #+#             */
/*   Updated: 2016/11/07 00:07:34 by mrobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_lstlen_counter(t_tetromino *begin_list)
{
	int count;

	count = 0;
	while (begin_list)
	{
		++count;
		begin_list = begin_list->next;
	}
	return (count);
}
