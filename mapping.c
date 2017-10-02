/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krashid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/06 16:02:25 by krashid-          #+#    #+#             */
/*   Updated: 2017/09/24 17:43:19 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define I i[0]
#define J i[1]
#define K i[2]

int		sqroot(int nb)
{
	int div;

	div = 1;
	while ((nb / div) > div)
		div++;
	return (div);
}

char	**map_malloc(int nb)
{
	char	**map;
	int		i[2];
	int		size;

	I = 0;
	J = -1;
	size = sqroot(4 * nb);
	map = ft_memalloc(sizeof(char *) * (size + 1));
	while (++J < size)
	{
		(!(map[J] = ft_memalloc(sizeof(char) * (size + 1)))) ? error(1) : 0;
		ft_memset(map[J], '.', size);
	}
	return (map);
}

char	**first_fill(char ***tab, int nb)
{
	char	**map;
	int		i;
	int		size;

	map = map_malloc(nb);
	while (!backtracking(map, tab))
	{
		i = 0;
		while (map[i])
			free(map[i++]);
		free(map);
		map = ft_memalloc(sizeof(char *) * (i + 2));
		size = i + 1;
		i = 0;
		while (i < size)
		{
			(!(map[i] = ft_memalloc(sizeof(char) * (size + 1)))) ? error(1) : 0;
			ft_memset(map[i], '.', size);
			i++;
		}
	}
	return (map);
}

int		backtracking(char **map, char ***tetri)
{
	int	i[2];

	I = 0;
	if (!(*tetri))
		return (1);
	while (map[I] && *tetri)
	{
		J = 0;
		while (map[I][J])
		{
			if (is_available(map, I, J, *tetri))
			{
				fillin_the_map(map, I, J, *tetri);
				if (backtracking(map, tetri + 1))
					return (1);
				take_off_tetri(map, I, J, *tetri);
			}
			++J;
		}
		++I;
	}
	return (0);
}
