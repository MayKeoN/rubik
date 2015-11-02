/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rubik_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <ymonfray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 03:05:47 by ymonfray          #+#    #+#             */
/*   Updated: 2015/10/27 03:05:47 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				g_order[3][6] = {{0, 1, 2, 3, 5, 4}, {4, 3, 5, 1, 0, 2}, {0, 5, 2, 4, 1, 3}};

#include "ft_rubik.h"

void			rotate_side_init(t_cube *cube, t_face *rot[6], int side)
{
	int			j;

	j = 0;
	while (j < 6)
	{
		rot[j] = cube->face[g_order[side][j]];
		j++;
	}
	if (side == 1)
		rot[3]->cell = rot[3]->dn;
	else if (side == 2)
	{
		rot[1]->cell = rot[1]->lf;
		rot[2]->cell = rot[2]->dn;
		rot[3]->cell = rot[3]->rt;
	}
}

void			rotate_side_face(t_face *rot[6], int dir, int row, int side)
{
	int			i;

	i = 0;
	if (row != 1)
	{
		while (i < 9)
		{
			if (row)
				rot[4]->cell[i] = ((!dir) * (!row) + (dir) * (row)) ? ((side) ? rot[4]->lf[i] : rot[4]->rt[i]) : ((side) ? rot[4]->rt[i] : rot[4]->lf[i]);
			else
				rot[5]->cell[i] = ((!dir) * (!row) + (dir) * (row)) ? ((side) ? rot[5]->lf[i] : rot[5]->rt[i]) : ((side) ? rot[5]->rt[i] : rot[5]->lf[i]);

			// rot[(row) ? 4 : 5]->cell[i] = ((!dir) * (row == 0) + (dir) * (row != 0)) ?\
			// ((side) ? rot[(row) ? 4 : 5]->lf[i] : rot[(row) ? 4 : 5]->rt[i]) : ((side) ? rot[(row) ? 4 : 5]->rt[i] : rot[(row) ? 4 : 5]->lf[i]);
			i++;
		}
		rot[(row) ? 4 : 5] = init_face_link(rot[(row) ? 4 : 5]);
	}
	rot[0]->cell = rot[0]->up;
	rot[1]->cell = rot[1]->up;
	rot[2]->cell = rot[2]->up;
	rot[3]->cell = rot[3]->up;
}

t_cube			*rotate_side(t_cube *cube, int dir, int side, int row)
{
	int			i;
	int			j;
	t_face		*rot[6];

	rotate_side_init(cube, rot, side);
	j = (dir) ? 2 : 0;
	while (j >= 0 && j < 3)
	{
		i = 0;
		while (i < 3)
		{
			if (side)
				swap(rot[j]->cell[(3 * row) + i], rot[j + 1]->cell[(3 * row) + i]);
			else
				swap(rot[j]->cell[row + (i * 3)], rot[j + 1]->cell[row + (i * 3)]);				

			i++;
		}
		j += (dir) ? -1 : 1;
	}
	rotate_side_face(rot, dir, row, side);
	// for (int z = 0;z < 6;z++)
	// 	rot[z] = init_face_link(rot[z]);
	return (cube);
}