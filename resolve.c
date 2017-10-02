/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krashid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 20:28:32 by krashid-          #+#    #+#             */
/*   Updated: 2017/09/24 18:06:01 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_available(char **map, int y, int x, char **tetri)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetri[i][j] && (!map[y + i] || map[y + i][x + j] != '.'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	take_off_tetri(char **map, int y, int x, char **tetri)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (!map[y + i])
			break ;
		j = 0;
		while (j < 4)
		{
			if (!map[y + i][x + j])
				break ;
			if (tetri[i][j] == map[i + y][j + x])
				map[i + y][j + x] = '.';
			j++;
		}
		i++;
	}
}

void	fillin_the_map(char **map, int y, int x, char **tetri)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (!map[y + i])
			break ;
		j = 0;
		while (j < 4)
		{
			if (!map[y + i][x + j])
				break ;
			if (tetri[i][j])
				map[i + y][j + x] = tetri[i][j];
			j++;
		}
		i++;
	}
}
