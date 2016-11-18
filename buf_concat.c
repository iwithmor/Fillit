/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 22:25:50 by iwithmor          #+#    #+#             */
/*   Updated: 2016/10/28 22:25:55 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	BUF_CONCAT.C
**		COMBINES TWO STRINGS:
**		S1 = PREVIOUSLY READ BYTES
**		S2 = NEW BUFFER
*/

char	*buf_concat(char *s1, char *s2)
{
	char	*res;
	int		s1len;
	int		s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	res = (char *)malloc(s1len + s2len + 1);
	if (!res)
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcpy(&res[s1len], s2);
	res[s1len + s2len] = '\0';
	return (res);
}
