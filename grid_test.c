/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 02:09:02 by bhamdi            #+#    #+#             */
/*   Updated: 2017/08/14 11:51:11 by krashid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define I i[0]
#define J i[1]
#define K i[2]
#define L i[3]
#define LINK i[4]

static void	l_affect_char(char ***tab, int i[5], char lettre, int nbtab)
{
	K + 1 < 4 && (tab[nbtab][J][K + 1] == lettre ||
			tab[nbtab][J][K + 1] == '#') ? LINK++ : 0;
	J + 1 < 4 && (tab[nbtab][J + 1][K] == lettre ||
			tab[nbtab][J + 1][K] == '#') ? LINK++ : 0;
	K - 1 >= 0 && (tab[nbtab][J][K - 1] == lettre ||
			tab[nbtab][J][K - 1] == '#') ? LINK++ : 0;
	J - 1 >= 0 && (tab[nbtab][J - 1][K] == lettre ||
			tab[nbtab][J - 1][K] == '#') ? LINK++ : 0;
}

/*
 ** verification de nblink dans chaques tetriminos
 */

int			test_grille(char ***tab, char lettre, int nbtab)
{
	int i[5];

	J = 0;
	I = 0;
	LINK = 0;
	while (J < 4)
	{
		K = 0;
		while (K < 4)
		{
			if (tab[nbtab][J][K] == '#' && (tab[nbtab][J][K] = lettre))
				l_affect_char(tab, i, lettre, nbtab);
			else
				tab[nbtab][J][K] = '\0';
			K++;
		}
		J++;
	}
	move_tetri_x(tab, nbtab);
	move_tetri_y(tab, nbtab);
	return (LINK);
}

/*
 ** malloc de tab
 */

char		***malloc_tab(int nb)
{
	char	***tab;
	int		i;
	int		j;

	i = 0;
	(!(tab = ft_memalloc(sizeof(char**) * nb + 1))) ? error(1) : NULL;
	while (i < nb)
	{
		(!(tab[i] = ft_memalloc(sizeof(char*) * 5))) ? error(1) : NULL;
		j = -1;
		while (++j < 4)
			(!(tab[i][j] = ft_memalloc(sizeof(char) * 5))) ? error(1) : NULL;
		i++;
	}
	return (tab);
}

/*
 ** metre les tetriminos en tab
 */

char		***split_tetris(char *s, int nb, char ***tab)
{
	int		i[3];

	I = 0;
	while (I < nb)
	{
		J = 0;
		while (J < 5)
		{
			K = 0;
			while (K < 5)
			{
				if ((*s == '\n' || *s == '\0') && *(s - 1) == '\n')
				{
					s++;
					break ;
				}
				tab[I][J][K] = *s;
				((K++) || 1) ? (s++) : 0;
			}
			J++;
		}
		I++;
	}
	return (tab);
}
