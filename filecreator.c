/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecreator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 14:24:26 by bhamdi            #+#    #+#             */
/*   Updated: 2017/09/24 18:42:19 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

#define BUFF 546
#define NBTETRIS i[0]
#define NBTAB i[1]
#define LINK i[2]

void	error(int i)
{
	i = 1;
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
			nbendline != 4 ? error(1) : (nbendline = 0);
			nbsharp != 4 ? error(1) : (nbsharp = 0);
			nbpoint != 12 ? error(1) : (nbpoint = 0);
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
	if (!str)
		error(1);
	while (str[i])
	{
		str[i] == '\n' ? j++ : 0;
		str[i] != '#' && str[i] != '.' && str[i] != '\n' ? error(1) : 0;
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
	verif_file(str);
	NBTETRIS = nbtetriminos(str);
	NBTETRIS > 26 ? error(1) : NULL;
	tab = malloc_tab(NBTETRIS);
	tab = split_tetris(str, NBTETRIS, tab);
	lettre = 'A';
	NBTAB = 0;
	while (NBTAB < NBTETRIS)
	{
		LINK = test_grille(tab, lettre, NBTAB);
		(LINK != 6 && LINK != 8) ? error(1) : 0;
		lettre++ ? NBTAB++ : 0;
	}
	map = first_fill(tab, NBTAB);
	NBTAB = 0;
	while (map[NBTAB])
		ft_putendl(map[NBTAB++]);
	return (0);
}
