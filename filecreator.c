/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecreator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 14:24:26 by bhamdi            #+#    #+#             */
/*   Updated: 2017/08/14 12:39:47 by krashid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BUFF 546
#define NBTETRIS i[0]
#define NBTAB i[1]
#define LINK i[2]

/*
** fonction error
*/

/*void	error(int i)
{
	i == 1 ? ft_putendl("error file does not exist") : 0;
	i == 2 ? ft_putendl("error + retour ligne a la fin") : 0;
	i == 3 ? ft_putendl("error trop de tetriminos") : 0;
	i == 4 ? ft_putendl("error nombre de tetriminos < 1") : 0;
	i == 5 ? ft_putendl("error nombre de ligne dans une tetriminos") : 0;
	i == 6 ? ft_putendl("error nombre de diese dans une tetriminos") : 0;
	i == 7 ? ft_putendl("error nombre de point dans une tetriminos") : 0;
	i == 8 ? ft_putendl("error de lien entre les diese") : 0;
	i == 9 ? ft_putendl("error char interdit") : 0;
	i == 10 ? ft_putendl("error tetriminos non valide") : 0;
	i == 11 ? ft_putendl("error dans malloc de tab") : 0;
	i == 12 ? ft_putendl("error fichier vide") : 0;
	exit(0);
}
*/

void	error()
{
	ft_putendl("error");
	exit(0);
}
/*
** comptage et validation du tetriminos
*/

int		nbtetriminos(char *s)
{
	int		nb;
	int		nbendline;
	int		nbsharp;
	int		nbpoint;

	nb = 0;
	nbendline = 1;
	nbsharp = 0;
	nbpoint = 0;
	!s ? error(1) : 0;
	while (*s)
	{
		*s == '#' ? (nbsharp++) : 0;
		*s == '.' ? (nbpoint++) : 0;
		*s == '\n' ? (nbendline++) : 0;
		s++;
		if ((*(s + 1) == '\0') || (*s == '\n' && *(s + 1) == '\n'))
		{
			nbendline != 4 ? error(5) : (nbendline = 0);
			nbsharp != 4 ? error(6) : (nbsharp = 0);
			nbpoint != 12 ? error(7) : (nbpoint = 0);
			(nb++) || 1 ? s++ : 0;
		}
	}
	return (nb);
}

/*
** lire le fichier
*/

char	*ft_get_file(int ac, char *av[])
{
	int		fd;
	int		ret;
	char	buf[BUFF];
	char	*str;

	str = NULL;
	if ((ac == 2) && (!((fd = open(av[1], O_RDONLY)) < 1)))
	{
		(!(open(av[1], O_RDONLY))) ? error(1) : NULL;
		while ((ret = read(fd, buf, BUFF)) > 0)
		{
			buf[ret] = '\0';
			str = ft_strjoin(str, buf);
		}
		close(fd);
		return (str);
	}
	else
		error(1);
	return (0);
}

/*
** verification de validite de tetriminos
*/

int		verif_file(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		str[i] == '\n' ? j++ : 0;
		str[i] != '#' && str[i] != '.' && str[i] != '\n' ? error(9) : 0;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if ((str[i + 1] == '\0' && str[i - 1] == '\n') || (j + 1) % 5)
			error(1);
		i++;
	}
	return (0);
}

/*
** fonction main
*/

int		main(int argc, char *argv[])
{
	char	*str;
	char	***tab;
	int		i[3];
	char	lettre;
	char	**map;

	str = ft_get_file(argc, argv);
	NBTETRIS = nbtetriminos(str);
	NBTETRIS >= 26 ? error(3) : NULL;
	verif_file(str);
	tab = malloc_tab(NBTETRIS);
	tab = split_tetris(str, NBTETRIS, tab);
	free(str);
	NBTAB = 0;
	lettre = 'A';
	while (NBTAB < NBTETRIS)
	{
		LINK = test_grille(tab, lettre, NBTAB);
		(LINK != 6 && LINK != 8) ? error(8) : 0;
		lettre++;
		NBTAB++;
	}
	map = first_fill(tab, NBTAB);
	NBTAB = 0;
	while (map[NBTAB])
		printf("%s\n", map[NBTAB++]);
	return (0);
}
