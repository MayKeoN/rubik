/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rubik_jungle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <ymonfray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/28 08:54:17 by ymonfray          #+#    #+#             */
/*   Updated: 2015/10/28 08:54:21 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rubik.h"

int			g_trees[18] = {
	3, 4, 5,\
	0, 1, 2,\
	9, 10, 11,\
	6, 7, 8,\
	15, 16, 17,\
	12, 13, 14};

int				g_jungle_combo[18][3] = {\
	{0, 0, 0}, {0, 0, 1}, {1, 0, 2},\
	{1, 0, 0}, {1, 0, 1}, {0, 0, 2},\
	{0, 1, 0}, {0, 1, 1}, {1, 1, 2},\
	{1, 1, 0}, {1, 1, 1}, {0, 1, 2},\
	{0, 2, 0}, {0, 2, 1}, {1, 2, 2},\
	{1, 2, 0}, {1, 2, 1}, {0, 2, 2}};

char			g_jungle_ans[18][4] = {\
	"L", "M", "R",\
	"L\'", "M\'", "R\'",\
	"U", "E", "D",\
	"U\'", "E\'", "D\'",\
	"F", "S", "B",\
	"F\'", "S\'", "B\'"};

char			*g_color_FU[6] = {"\033[46m", "\033[45m", "\033[44m", "\033[43m", "\033[42m", "\033[41m"};

int					jungle_check_face(t_cube *cube, int n)
{
	int				j;

	j = 1;
	while (j < 9)
	{
		if (*cube->face[n]->cell[j] != *cube->face[n]->cell[0])
			return (0);
		j++;
	}
	return (1);
}


int					jungle_check(t_cube *cube, int mode)
{
	int				i;
	int				j;

	if (mode < 7)
	{
		i = 0;
		j = 0;
		while (i < 6)
		{
			if (jungle_check_face(cube, i))
				j++;
				// return (1);
			// while (j < 9)
			// {
			// 	if (cube->face[i]->cell[j] != cube->face[i]->cell[0])
			// 		return (0);
			// 	j++;
			// }
			i++;
		}
	}
	else
	{
		if (jungle_check_face(cube, 1))
		{
			
		}
	}
	return (j);
}


t_jungle			**jungle_init(t_jungle **jgl)
{
	int			i;
	int			j;

	jgl = NULL;
	if ((jgl = (t_jungle **)malloc(sizeof(t_jungle *) * 18)))
	{
		i = 0;
		while (i < 18)
		{
			if ((jgl[i] = (t_jungle *)malloc(sizeof(t_jungle))) == NULL)
				return (NULL);
			i++;
		}
		i = 0;
		while (i < 18)
		{
			j = 0;
			jgl[i]->bl = (int *)malloc(sizeof(int) * 18);
			while (j < 18)
			{
				jgl[i]->cct[j] = jgl[j];
				// printf("FUCKED\n");
				jgl[i]->bl[j] = (g_trees[j] == i) ? 2 : 0;
				j++;
			}
			i++;
		}
	}
	return (jgl);
}

void				jungle_run(t_cube *cube, int cur, int depth, t_jungle *jgl, int *moves, int maxdepth, int maxface)
{
	int				i;
	int				j;
	int				rnbr;
	int				rpn[18] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};

	if (depth < maxdepth)
	{
		j = 0;
		// while (j < 18)
		// {
		// 	rnbr = (rand() % 180000) / 10000;
		// 	swap(&rpn[rnbr], &rpn[17 - rnbr]);
		// 	j++;
		// }
		// j = 0;
		i = 0;
		// while (j < 18)
		while (i < 18)
		{
			// i = rpn[j];
			if (i == 1 || i == 4 || i == 7 || i == 10 || i == 13 || i == 16)
			{

				i++;
				// j++;
				// continue;
			}else
			{

			moves[depth] = i;
				printf("\n");//!ST===================================================\n");

				for (int k = 0;k < 18;k++)
					printf("[%s%s%s] ", (jgl->bl[k]) ? (g_color_FU[6 - jgl->bl[k]]) : "", (jgl->bl[k]) ? ft_itoa(jgl->bl[k]) : " \x1B[0m", "\x1B[0m");
				printf("!ST===================================================");
				printf("CURRENT: %d\tDEPTH:%d\tIter: %d\n", cur, depth, i);
				// print_cube(cube, 0);
			// if (moves[depth])
			if (jgl->bl[i] == 2 || i == g_trees[cur])
			{
				for (int k = 0; k < 18;k++)
					jgl->bl[k] = 0;
				jgl->bl[i] = (g_trees[cur] != i) ? 0 : 2;
			}
			else
			{
				if (jgl->bl[i] == 1)
				{
				// printf("SECOND CALL_SECOND CALL_SECOND CALL_SECOND CALL_SECOND CALLSECOND CALL_SECOND CALL_SECOND CALL_SECOND CALL_SECOND CALL\n");
				// usleep(1500000);	
					for (int k = 0; k < 18;k++)
						jgl->bl[k] = 0;
					jgl->bl[g_trees[cur]] = 2;
					jgl->bl[i] = 2;
				}
				else
				{
					for (int k = 0; k < 18;k++)
						jgl->bl[k] = 0;
					jgl->bl[g_trees[cur]] = 2;
					jgl->bl[i] = 1;
				}

				// usleep(8400);
				jgl->cct[i]->bl = jgl->bl;
				cube = rotate_side(cube, g_jungle_combo[i][0], g_jungle_combo[i][1], g_jungle_combo[i][2]);

				if (jungle_check(cube, maxface) >= maxface)
				{
					printf("$$$$$$$$$$$$$$$$$$$$$$$$JJJJJJJJJJJJJACCCCCCCKKKKKKKPPPPPPPPPOOOOOOTTTTTT$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
					print_cube(cube, 0);
				printf("===================================================\n");
				printf("RUNNING TEST\n");
				printf("CURRENT: %d\tDEPTH:%d\tIter: %d\n", cur, depth, i);
				for (int k = 0;k < 18;k++)
					printf("[%d] ", jgl->bl[k]);
				printf("++=================================++\n");
					for (int k = 0;k < depth + 1;k++)
						printf("%s ", g_jungle_ans[moves[k]]);
					printf("++MOVES\n");				
					usleep(500000);
					// exit(0);
				}
				// print_cube(cube, 0);
				jungle_run(cube, i, depth + 1, jgl->cct[i], moves, maxdepth, maxface);
				// for (int k = 0;k < 18;k++)
				// 	moves[k] = 0;
				// moves[i] = 0;
				cube = rotate_side(cube, g_jungle_combo[g_trees[i]][0], g_jungle_combo[g_trees[i]][1], g_jungle_combo[g_trees[i]][2]);
			}
			// j++;
			i++;
			}
		}
	}
	return ;
}

