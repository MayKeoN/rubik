/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rubik_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <ymonfray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 20:26:43 by ymonfray          #+#    #+#             */
/*   Updated: 2015/10/25 20:26:44 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rubik.h"

int				g_combo[18][3] = {\
	{0, 0, 0}, {0, 0, 1}, {1, 0, 2},\
	{1, 0, 0}, {1, 0, 1}, {0, 0, 2},\
	{0, 1, 0}, {0, 1, 1}, {1, 1, 2},\
	{1, 1, 0}, {1, 1, 1}, {0, 1, 2},\
	{0, 2, 0}, {0, 2, 1}, {1, 2, 2},\
	{1, 2, 0}, {1, 2, 1}, {0, 2, 2}};

int			input_parse(char *str)
{
	int		n;

	if (str[0] == 'L')
		n = 0;
	else if (str[0] == 'M')
		n = 1;
	else if (str[0] == 'R')
		n = 2;
	else if (str[0] == 'U')
		n = 6;
	else if (str[0] == 'E')
		n = 7;
	else if (str[0] == 'D')
		n = 8;
	else if (str[0] == 'F')
		n = 12;
	else if (str[0] == 'S')
		n = 13;
	else if (str[0] == 'B')
		n = 14;
	else
	{
		n = 42;
		printf("Wrong Entry !\n");
		return (n);
	}
	n += (str[1] == '\'') ? 3 : 0;
	
	return (n);
}

void		input_loop_move(int *xy)
{
	char		scann[3];

	xy[0] = 0;
	xy[1] = 0;
	scann[0] = 0;
	scann[1] = 0;
	scann[2] = 0;
	ft_putstr("Enter Move...: ");
	read(1, &scann, 3);
	*xy = input_parse(scann);
	// printf("SCANNNED= %s\n", scann);
	// if (scann[0] == 'L')
	// 	xy[0] = 0;
	// else if (scann[0] == 'M')
	// 	xy[0] = 1;
	// else if (scann[0] == 'R')
	// 	xy[0] = 2;
	// else if (scann[0] == 'U')
	// 	xy[0] = 6;
	// else if (scann[0] == 'E')
	// 	xy[0] = 7;
	// else if (scann[0] == 'D')
	// 	xy[0] = 8;
	// else if (scann[0] == 'F')
	// 	xy[0] = 12;
	// else if (scann[0] == 'S')
	// 	xy[0] = 13;
	// else if (scann[0] == 'B')
	// 	xy[0] = 14;
	// else
	// {
	// 	xy[0] = 42;
	// 	printf("Wrong Entry !\n");
	// 	// return;
	// }
	// xy[1] = (scann[1] == '\'') ? 3 : 0;
	// xy[1] += xy[0];
	printf("Way: %d\tSide:%d\tRow: %d\n", g_combo[xy[0]][0], g_combo[xy[0]][1], g_combo[xy[0]][2]);
}

void		input_loop(int *xy)
{
	char		scann[3];

	ft_putstr("Way (0 - 1) : ");
	read(1, &scann, 3);
	xy[0] = scann[0] - 48;

	ft_putstr("Side (0 - 1 - 2) : ");
	read(1, &scann, 2);
	xy[1] = scann[0] - 48;

	ft_putstr("Row (0 - 1 - 2) : ");
	read(1, &scann, 2);
	xy[2] = scann[0] - 48;

	// ft_putstr("Face (0 - 1 - 2 - 3) : ");
	// read(1, &scann, 2);
	// xy[3] = scann[0] - 48;
	xy[3] = 0;	
	printf("Way: %d\tSide:%d\tRow: %d\tFace: %d\n", xy[0], xy[1], xy[2], xy[3]);
}

int			main(int ac, char **av)
{
	t_cube	*cube;
	t_jungle **jgl;
	int		*xy;
	int		count;

	count = 3;
	xy = (int *)malloc(sizeof(int) * 4);
	if (ac > 1)
	{
		srand(time(NULL));
		printf("%s\n", av[1]);
		cube = init_cube();
		print_cube(cube, 0);
		while (*xy != 42)
		{
			if (count < ac)
			{	
				*xy = input_parse(av[count]);
				cube = rotate_side(cube, g_combo[*xy][0], g_combo[*xy][1], g_combo[*xy][2]);
				print_cube(cube, 0);
				printf("ROTATING\n");			
				usleep(24242);
			}
			else
			{
				break;
				// jgl = jungle_init(jgl);
				// jungle_run(cube, 0, 0, jgl[0]);
				// input_loop_move(xy);
			}
			// if (*xy != 42)
				printf("MAIN LOOP Count %d\n", count);
			count++;
			// input_loop(xy);
			// if (xy[0] != 2)
			// {	
			// 	cube = rotate_side(cube, xy[0], xy[1], xy[2]);
			// 	print_cube(cube, xy[3]);
			// }
			// else
			// 	print_cube(cube, xy[3]);
			// print_cube(cube, 2);
			// print_cube(cube, 3);
		}
		int *moves;

		moves = (int *)malloc(sizeof(int) * 20);
		for (int i = 0;i < 20;i++)
			moves[i] = 0;
		jgl = jungle_init(jgl);
		jungle_run(cube, 0, 0, jgl[0], moves, ft_atoi(av[1]), ft_atoi(av[2]));
		// jungle_run(cube, 0, 0, jgl[0], moves, ac);
		// print_cube(cube, 0);
	}
	return (0);
}