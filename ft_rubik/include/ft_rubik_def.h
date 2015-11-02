/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rubik_def.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <ymonfray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/25 20:26:20 by ymonfray          #+#    #+#             */
/*   Updated: 2015/10/25 20:26:21 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUBIK_DEF_H
# define FT_RUBIK_DEF_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <unistd.h>
# include <time.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"

// # include <SDL.h>
// # include <GLFW/glfw3.h>

typedef struct 			s_face
{
	int					**cell;
	int					**up;
	int					**dn;
	int					**lf;
	int					**rt;
}						t_face;

typedef struct 			s_cube
{
	t_face				*face[6];
}						t_cube;

typedef struct 			s_jungle
{
	int					*bl;
	struct s_jungle		*cct[18];
}						t_jungle;

#endif