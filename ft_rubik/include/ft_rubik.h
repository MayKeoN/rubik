/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rubik.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <ymonfray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 20:26:27 by ymonfray          #+#    #+#             */
/*   Updated: 2015/10/25 20:26:27 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUBIK_H
# define FT_RUBIK_H
# include "ft_rubik_def.h"

// int			g_trees[18] = {
// 	3, 4, 5,\
// 	0, 1, 2,\
// 	9, 10, 11,\
// 	6, 7, 8,\
// 	15, 16, 17,\
// 	12, 13, 14};

// int				g_combo[18][3] = {\
// 	{0, 0, 0}, {0, 0, 1}, {1, 0, 2},\
// 	{1, 0, 0}, {1, 0, 1}, {0, 0, 2},\
// 	{0, 1, 0}, {0, 1, 1}, {1, 1, 2},\
// 	{1, 1, 0}, {1, 1, 1}, {0, 1, 2},\
// 	{0, 2, 0}, {0, 2, 1}, {1, 2, 2},\
// 	{1, 2, 0}, {1, 2, 1}, {0, 2, 2}};

void			swap(int *a, int *b);

t_face			*init_face(int num);
t_face			*init_face_link(t_face *face);
t_cube			*init_cube(void);

t_cube			*rotate_side(t_cube *cube, int dir, int side, int row);
void			rotate_side_init(t_cube *cube, t_face *rot[6], int side);
void			rotate_side_face(t_face *rot[6], int dir, int row, int side);

void			print_cube(t_cube *cube, int n);
t_jungle		**jungle_init(t_jungle **jgl);
void			jungle_run(t_cube *cube, int cur, int depth, t_jungle *jgl, int *moves, int maxdepth, int maxface);


#endif