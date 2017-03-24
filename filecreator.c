/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecreator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 14:24:26 by bhamdi            #+#    #+#             */
/*   Updated: 2017/03/24 01:07:54 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "./libft/libft.h"
#define BUFF 546

char	***test_grille(char ***tab, int nbtetris);
char	***split_tetris(char *s, int nbtetris);
// fonction error
/**************************************/
void	error(int i)
{
	i == 1 ? ft_putendl("error file open") : NULL;
	i == 2 ? ft_putendl("error + retour ligne a la fin") : NULL;
	i == 3 ? ft_putendl("error trop de tetriminos") : NULL;
	i == 4 ? ft_putendl("error nombre de tetriminos < 1") : NULL;
	i == 5 ? ft_putendl("error nombre de ligne dans une tetriminos") : NULL;
	i == 6 ? ft_putendl("error nombre de diese dans une tetriminos") : NULL;
	i == 7 ? ft_putendl("error nombre de point dans une tetriminos") : NULL;
	i == 8 ? ft_putendl("error de lien entre les diese") : NULL;
	i == 9 ? ft_putendl("error char interdit") : NULL;
	i == 10 ? ft_putendl("error tetriminos non valide") : NULL;
	i == 11 ? ft_putendl("error dans malloc de tab") : NULL;
	exit(0);
}
// comptage et validation du tetriminos
/**************************************/
int		nbtetriminos(char *s)
{
	int	nb;
	int	nbendline;
	int	nbsharp;
	int	nbpoint;

	nb = 0;
	nbendline = 1;
	nbsharp = 0;
	nbpoint = 0;
	while (*s)
	{
		*s == '#' ? (nbsharp++) : 0;
		*s == '.' ? (nbpoint++) : 0;
		*s == '\n' ? (nbendline++) : 0;
		s++;
		if ((*(s + 1) == '\0') || (*s == '\n' && *(s + 1) == '\n'))
		{
			nbendline != 4  ? error(5) : (nbendline = 0);
			nbsharp != 4 ? error(6) : (nbsharp = 0);
			nbpoint != 12 ? error(7) : (nbpoint = 0);
			(nb++) || 1 ? s++ : 0;
		}
	}
	return (nb);
}
// lire le fichier
/**************************************/
char	*ft_get_file(int ac, char *av[])
{
	int		fd;
	int		ret;
	char	buf[BUFF];
	char	*str;

	str = NULL;
	if ((ac > 1) && (!((fd = open(av[1], O_RDONLY)) < 1)))
	{
		(!(open(av[1], O_RDONLY))) ? error(4) : NULL;
		while ((ret = read(fd, buf, BUFF)))
		{
			buf[ret] = '\0';
			str = ft_strjoin(str, buf);
		}
		close(fd);
		return (str);
	}
	else
		error(1);
	return(0);
}
// verification de validite de tetriminos
/**************************************/
int		verif_file(char *str)
{
	int	i;
	int	j;

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
			error(2);
		i++;
	}
	return(0);
}
// fonction main
/**************************************/
int		main(int argc, char *argv[])
{
	char	*str;
	char	***tab;
	int		nbtetris;

	str =  ft_get_file(argc, argv);
	nbtetris = nbtetriminos(str);
	verif_file(str);
	tab = split_tetris(str, nbtetris);
	nbtetris > 26 ? error(3) : NULL;
	printf("%s", str);
	printf("nbtetriminos [%d]\n", nbtetris);
	test_grille(tab, nbtetris);
	int i = 0, j = 0, k = 0;
	while (i < nbtetris)
	{
		j = -1;
		while (++j <4)
		{
			k = -1;
			while (++k < 4)
				printf("%c", tab[i][j][k]);
		}
	}
	return (0);
}
