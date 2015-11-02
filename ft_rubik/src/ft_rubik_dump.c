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
		// printf("I: %d\tN: %d\n", i, (i/3) + (3 * (i % 3)));
		// printf("I: %d\tCell: %d\n", i, *face->cell[(i/3) + (3 * (i % 3))]);
		face->up[i] = face->cell[i];
		i++;
	}

	i = 0;
	while (i < 9)
	{

		face->dn[i] = face->cell[8 - i];
		i++;
	}

	i = 0;
	while (i < 9)
	{
		face->lf[i] = face->cell[3 * (2 - i % 3) + (i / 3)];
		i++;
	}
	i = 0;
	while (i < 9)
	{
		face->rt[i] = face->cell[3 * (i % 3) + (2 - (i / 3))];	
		// printf("%d ", 3 * (i % 3) + (2 - (i / 3)));
		
		i++;
	}
	// printf("\n");

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
			// printf("%d\n", face->cell[i][0]);
			i++;
		}
		face = init_face_link(face);
	}
	return (face);
}


// t_cube			*init_cube_link(t_cube *cube)
// {
// 	int			i;
// 	int			j;

// 	i = 0;
// 	while (i < 6)
// 	{
// 		j = (i != 5) ? i + 1 : 0;
// 		cube->face[i]->up = cube->face[j]->cell;
// 		cube->face[i]->dn = cube->face[j]->cell;
// 		cube->face[i]->lf = cube->face[j]->cell;
// 		cube->face[i]->rt = cube->face[j]->cell;
// 		i++;
// 	}
// 	return (cube);
// }

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
		// cube = init_cube_link(cube);
	}
	return (cube);
}
// 1	4
// 2	1
// 3	2
// 4	3

// 2	3	4
// 1	1	1
// 3	2	2
// 4	4	3

int			g_order[3][6] = {{0, 1, 2, 3, 5, 4}, {4, 3, 5, 1, 0, 2}, {0, 5, 2, 4, 1, 3}};

t_cube			*rotate_side(t_cube *cube, int dir, int side, int row)
{
	int			i;
	int			j;
	t_face		*rot[6];

	j = 0;
	while (j < 6)
	{
		rot[j] = cube->face[g_order[side][j]];
		j++;
	}
	if (side == 1)
	{
		// rot[0] = cube->face[4];
		// rot[1] = cube->face[3];
		// rot[2] = cube->face[5];
		// rot[3] = cube->face[1];

		// // rot[4] = cube->face[0];
		// // rot[5] = cube->face[2];

		rot[3]->cell = rot[3]->dn;
	}
	else if (side == 2)
	{
		// rot[0] = cube->face[0];
		// rot[1] = cube->face[5];
		// rot[2] = cube->face[2];
		// rot[3] = cube->face[4];

		// rot[4] = cube->face[1];
		// rot[5] = cube->face[3];
		rot[0]->cell = rot[0]->up;
		rot[1]->cell = rot[1]->lf;
		rot[2]->cell = rot[2]->dn;
		rot[3]->cell = rot[3]->rt;
	}
	else
	{
		// rot[0] = cube->face[0];
		// rot[1] = cube->face[1];
		// rot[2] = cube->face[2];
		// rot[3] = cube->face[3];
		// rot[4] = cube->face[4];
		// rot[5] = cube->face[5];
	}
	j = (dir) ? 2 : 0;
	while (j >= 0 && j < 3)
	{
		i = 0;
		while (i < 3)
		{
			// if (dir)
			// 	swap(cube->face[j]->cell[3 + i], cube->face[j + 1]->cell[3 + i]);
			// else
			// 	swap(cube->face[j]->lf[3 + i], cube->face[j + 1]->lf[3 + i]);				

			// printf("I: %d\tR: %d\n", i, (side != 0) ? (3 * row) + i : row + (i * 3));
			if (side)
				swap(rot[j]->cell[(3 * row) + i], rot[j + 1]->cell[(3 * row) + i]);
			else
				swap(rot[j]->cell[row + (i * 3)], rot[j + 1]->cell[row + (i * 3)]);				

			i++;
		}
		j += (dir) ? -1 : 1;
	}

	rot[0]->cell = rot[0]->up;	
	rot[1]->cell = rot[1]->up;	
	rot[2]->cell = rot[2]->up;
	rot[3]->cell = rot[3]->up;
	// rot[4]->cell = rot[4]->up;	
	// rot[5]->cell = rot[5]->up;

	if (row != 1)
	{
		// if (side == 2)
		{
			for (int m = 0;m < 9;m++)
			{
				rot[(row) ? 4 : 5]->cell[m] = (dir * (row == 0) + (row != 0)) ? rot[(row) ? 4 : 5]->lf[m] : rot[(row) ? 4 : 5]->rt[m];
			}
			rot[(row) ? 4 : 5] = init_face_link(rot[(row) ? 4 : 5]);
			// if (!row)
			// {
			// }
			// else
			// {
			// 	for (int m = 0;m < 9;m++)
			// 		rot[4]->cell[m] = (dir) ? rot[4]->rt[m] : rot[4]->lf[m];
			// 	rot[4] = init_face_link(rot[4]);

			// }
			// for (int m = 0;m < 9;m++)
			// {
			// 	printf("HERE %d\n", (row == 0) ? 3 : 1);


			// 	if (!row)
			// 	{

			// 		swap(rot[5]->cell[m], (dir) ? rot[5]->lf[m] : rot[5]->rt[m]);
			// 	}
			// 	else
			// 	{

			// 		swap(rot[4]->cell[m], (dir) ? rot[4]->rt[m] : rot[4]->lf[m]);
			// 	}
				// cube->face[(row == 0) ? 3 : 1]->cell[m] = (dir) ? cube->face[(row == 0) ? 3 : 1]->rt[m] : cube->face[(row == 0) ? 3 : 1]->lf[m];
			// }
			// init_face_link(cube->face[(row == 0) ? 3 : 1]);
		}

	}

	// rot[4]->cell = rot[4]->up;	
	// rot[5]->cell = rot[5]->up;	
	// cube->face[0]->cell = cube->face[0]->up;
	// cube->face[1]->cell = cube->face[1]->up;
	// cube->face[2]->cell = cube->face[2]->up;
	// cube->face[3]->cell = cube->face[3]->up;
	// cube->face[4]->cell = cube->face[4]->up;
	// cube->face[5]->cell = cube->face[5]->up;
	// j = 0;
	// while (j < 4)
	// {
	// 	cube->face[g_order[side][j]]->cell = cube->face[g_order[side][j]]->up;
	// 	j++;
	// }
	return (cube);
}

// t_cube			*rotate_side(t_cube *cube, int dir, int side, int row)
// {
// 	int			i;
// 	int			j;

// 	j = side;
// 	while (j < side + 3)
// 	{
// 		i = 0;
// 		while (i < 3)
// 		{
// 			if (dir)
// 				swap(cube->face[j]->cell[3 * row + i], cube->face[j + 1]->cell[3 * row + i]);
// 			else
// 				swap(cube->face[j]->lf[3 * row + i], cube->face[j + 1]->lf[3 * row + i]);				
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (cube);
// }


// t_cube			*rotate_side(t_cube *cube)
// {

// 	return (cube);
// }
