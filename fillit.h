/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwithmor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 16:07:16 by iwithmor          #+#    #+#             */
/*   Updated: 2016/10/24 16:07:18 by iwithmor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE	21
# define MAX_SIZE	545
# include <fcntl.h>
# include "./libft/libft.h"

typedef struct		s_tetris
{
	char			letter;
	int				*x;
	int				*y;
	struct s_tetris	*next;
}					t_tetromino;

t_tetromino			*process_file(char *filename);
char				*read_file(int fd);
char				*buf_concat(char *s1, char *s2);
char				*validate_tetromino(char *buf);
char				**place(t_tetromino *piece, char **map, int mapsize);
char				**ft_remove(t_tetromino *piece, char **map, int mapsize);
char				**make_map(int size);
int					*store_data(char *filearray);
int					count_tetrominos(char *filearray);
int					tetromino_type(char *str);
int					is_straight(int *arr);
int					is_square(int *arr);
int					is_t(int *arr);
int					is_z(int *arr);
int					is_l(int *arr);
int					map_size(t_tetromino *piece);
int					is_in_map(t_tetromino *piece, char **map, int mapsize);
int					ft_lstlen_counter(t_tetromino *begin_list);
void				fillit(t_tetromino *firstpiece);
t_tetromino			*link_data(int *arr);
t_tetromino			*move_coordinates(t_tetromino *piece, int x, int y);
void				straight_square_coordinates(t_tetromino *piece, int shape);
void				t_coordinates(t_tetromino *piece, int shape);
void				z_coordinates(t_tetromino *piece, int shape);
void				l_coordinates(t_tetromino *piece, int shape);
void				print_map(char **map, int size);
void				fillit(t_tetromino *firstpiece);

#endif
