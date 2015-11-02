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

char			*g_color[6] = {"\033[46m", "\033[45m", "\033[44m", "\033[43m", "\033[42m", "\033[41m"};

#include "ft_rubik.h"

static void		print_face_inline(t_cube *cube, char *order, int side)
{
	int			i;
	int			j;
	int			n;
	int			**nums;
	char		*str;

	j = 0;
	str = order;
	while (j < 3)
	{
		// printf("Ord: %c\n", *order);
		while (*order != '\0')
		{
			n = *order++ - '0';
			if (n == -16)
			{
				printf("\t");
			}
			else
			{
				// printf("N= %d\n", n);
				if (side)
					nums = (side == 1) ? cube->face[n]->dn : ((side == 2) ? cube->face[n]->lf : cube->face[n]->rt);
				else
					nums = cube->face[n]->cell;
				// nums = cube->face[n]->cell;
				i = 0;
				while (i < 3)
				{
					printf("%s", g_color[*nums[3 * j + i] - 1]);
					// printf("%d ", *nums[3 * j + i]);
					printf("%s ", ((i != -1) ? " " : ft_itoa(*nums[3 * j + i])));
					printf("\x1B[0m");
					i++;
				}
				printf("\t");
			}
		}
		printf("\n");
		order = str;
		j++;
	}
	printf("\n");
}

static void		print_face(t_face *face, int side, int k)
{
	int		l;
	int		**nums;

	if (side)
		nums = (side == 1) ? face->dn : ((side == 2) ? face->lf : face->rt);
	else
		nums = face->up;
	l = 0;
	while (l < 9)
	{
		if (l % 3 == 0)
			if (k != 4)
				printf((k == 5) ? "\t\t\t\t" : "\t\t");
		printf("%s", g_color[*nums[l] - 1]);
		printf("%s ", ((l != -1) ? " " : ft_itoa(*nums[l])));
		printf("\x1B[0m"); 
		if ((l + 1) % 3 == 0)
		{
			if (k != 4)
				printf((k == 5) ? "\t\t\t\t" : "\t\t");
			// if (k < 2 || k > 4)
			printf("\n");			
		}
		l++;
	}	
}

void		print_cube(t_cube *cube, int n)
{
	int		k;

	k = 0;
	printf("==================-CUBE-======================\n");
	printf("=====UP VIEW=====\n");
	print_face_inline(cube, " 1", 0);
	print_face_inline(cube, " 2", 0);
	print_face_inline(cube, "435", 0);
	print_face_inline(cube, " 0", 0);

	// printf("=====RT VIEW=====\n");
	// print_face_inline(cube, "   5", 3);
	// print_face_inline(cube, "0123", 3);
	// print_face_inline(cube, "   4", 3);
	// // print_face_inline(cube, " 0", 3);

	// printf("=====DN VIEW=====\n");
	// print_face_inline(cube, " 0", 1);
	// print_face_inline(cube, "534", 1);
	// print_face_inline(cube, " 2", 1);
	// print_face_inline(cube, " 1", 1);

	// printf("=====LF VIEW=====\n");
	// print_face_inline(cube, " 4", 2);
	// print_face_inline(cube, "0321", 2);
	// print_face_inline(cube, " 5", 2);
	// print_face_inline(cube, " 0", 2);
	// while (k < 6)
	// {
	// 	print_face(cube->face[k], n, k);
	// 	printf("\n");
	// 	k++;
	// }
	printf("===============================================\n");
}