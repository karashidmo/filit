/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 02:09:02 by bhamdi            #+#    #+#             */
/*   Updated: 2017/03/24 06:01:41 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "./libft/libft.h"

void    error(int i);

// verification de nblink dans chaques tetriminos 
/**************************************/
char	***test_grille(char ***tab, int nbtetris)
{ 
	int i = 0;
	int j = 0;
	int k = 0;
	int nblink = 0;

	while (i < nbtetris)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				printf("tab %d%d%d = [%c]\n",i,j,k,tab[i][j][k]);
				if (tab[i][j][k] == '#')
				{
					k + 1 < 4 &&  tab[i][j][k + 1] == '#' ? nblink++ : 0;
					j + 1 < 4 && tab[i][j + 1][k] == '#' ? nblink++ : 0;
					k - 1 >= 0 && tab[i][j][k - 1] == '#' ? nblink++ : 0;
					j - 1 >= 0 && tab[i][j -1][k] == '#' ? nblink++ : 0;
					printf("%d %d %d = # --> nblink = [%d]\n",i,j,k,nblink);
				}
				k++;
			}
			j++;
		}
		printf("%d %d %d = # --> nblink = [%d]\n",i,j,k,nblink);
		nblink = 0;
		i++;
	}

	return(tab);
}
//  metre les tetriminos en tab
/**************************************/
char ***split_tetris(char *s, int nbtetris)
{
	char    ***tab;
	int        i;
	int        j;
	int        k;
	int		   t;
	i = 0;
	(!(tab = malloc(sizeof(char**) * nbtetris + 1))) ? error(11) : NULL;
	while (i < nbtetris)
	{
		(!(tab[i] = malloc(sizeof(char*) * 4))) ? error(11) : NULL;
		j = -1;
		while (++j < 4)
			(!(tab[i][j] = malloc(sizeof(char) * 4))) ? error(11) : NULL;
		i++;
	}
	i = 0;
	t = 0;
	while (i < nbtetris)
	{
		j = 0;
		while (j < 5)
		{
			k = 0;
			while (k < 5)
			{
				printf("%d %d %d = [%c]\n",i,j,k,s[t]);
				if ((s[t] == '\n') && s[t - 1] == '\n')
				{
					k = 0;
					j++;
				}
				tab[i][j][k] = s[t];
				printf("cette str est egale a %c\n", s[t]);
				k++;
				t++;
			}
			j++;
		}
		i++;
	}
	return (tab);
}
