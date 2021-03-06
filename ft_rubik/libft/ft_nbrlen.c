/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdambrev <mdambrev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 15:06:20 by mdambrev          #+#    #+#             */
/*   Updated: 2014/12/01 20:23:46 by mdambrev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_nbrlen(int x)
{
	int				y;
	unsigned int	a;

	y = 1;
	a = x;
	if (x < 0)
		a = -x;
	while (a > 9)
	{
		a /= 10;
		y++;
	}
	return (y);
}
