/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krashid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 20:47:24 by krashid-          #+#    #+#             */
/*   Updated: 2017/08/14 12:10:29 by krashid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		l_check_free_x(char ***tab, int nbtab)
{
	int		x;

	x = -1;
	while (++x < 4)
		if (tab[nbtab][0][x] != '\0')
			return (0);
	return (1);
}

void	move_tetri_y(char ***tab, int nbtab)
{
	int		x;
	int		y;

	while (l_check_free_x(tab, nbtab))
	{
		x = -1;
		while (++x < 4)
		{
			y = 0;
			while (++y < 4)
				if (tab[nbtab][y][x])
				{
					tab[nbtab][y - 1][x] = tab[nbtab][y][x];
					tab[nbtab][y][x] = '\0';
				}
		}
	}
}

/*
 *********************MOVE X******************
 */

/*
 ** return 1 if free
 ** return 0 if not free
 */

int		l_check_free_y(char ***tab, int nbtab)
{
	int		y;

	y = -1;
	while (++y < 4)
		if (tab[nbtab][y][0] != '\0')
			return (0);
	return (1);
}

void	move_tetri_x(char ***tab, int nbtab)
{
	int		x;
	int		y;

	while (l_check_free_y(tab, nbtab))
	{
		y = -1;
		while (++y < 4)
		{
			x = 0;
			while (++x < 4)
				if (tab[nbtab][y][x])
				{
					tab[nbtab][y][x - 1] = tab[nbtab][y][x];
					tab[nbtab][y][x] = '\0';
				}
		}
	}
}
