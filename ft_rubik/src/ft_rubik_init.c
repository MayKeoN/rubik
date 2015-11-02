/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rubik_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <ymonfray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 20:29:03 by ymonfray          #+#    #+#             */
/*   Updated: 2015/10/25 20:29:03 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rubik.h"

void			swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

t_face			*init_face_link(t_face *face)
{
	int			i;

	i = 0;
	while (i < 9)
	{
		face->up[i] = face->cell[i];
		face->dn[i] = face->cell[8 - i];
		face->lf[i] = face->cell[3 * (2 - i % 3) + (i / 3)];
		face->rt[i] = face->cell[3 * (i % 3) + (2 - (i / 3))];	
		i++;
	}
	return (face);
}

t_face			*init_face(int num)
{
	t_face		*face;
	int			i;

	i = 0;
	face = NULL;
	if ((face = (t_face *)malloc(sizeof(t_face))))
	{
		face->cell = (int **)malloc(sizeof(int *) * 9);
		face->up = (int **)malloc(sizeof(int *) * 9);
		face->dn = (int **)malloc(sizeof(int *) * 9);
		face->lf = (int **)malloc(sizeof(int *) * 9);
		face->rt = (int **)malloc(sizeof(int *) * 9);
		while (i < 9)
		{
			face->cell[i] = (int *)malloc(sizeof(int));
			face->cell[i][0] = num;
			i++;
		}
		face = init_face_link(face);
	}
	return (face);
}

t_cube			*init_cube(void)
{
	t_cube		*cube;
	int			i;

	i = 0;
	cube = NULL;
	if ((cube = (t_cube *)malloc(sizeof(t_cube))))
	{
		while (i < 6)
		{
			cube->face[i] = init_face(i + 1);
			i++;
		}
	}
	return (cube);
}
