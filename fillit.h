/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 01:22:36 by bhamdi            #+#    #+#             */
/*   Updated: 2017/09/24 18:24:24 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

void	error(int i);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		nbtetriminos(char *s);
int		verif_file(char *str);
char	***malloc_tab(int nb);
void	*ft_memalloc(size_t size);
void	ft_putendl(char const *s);
void	ft_putendl(char const *s);
size_t	ft_strlen(const char *str);
int		main(int argc, char *argv[]);
char	*ft_get_file(int ac, char *av[]);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	***split_tetris(char *s, int nb, char ***tab);
int		test_grille(char ***tab, char lettre, int nbtab);
void	move_tetri_x(char ***tab, int nbtab);
void	move_tetri_y(char ***tab, int nbtab);
char	**map_malloc(int nbtab);
int		sqroot(int nb);
int		l_check_free_x(char ***tab, int nbtab);
int		l_check_free_y(char ***tab, int nbtab);
void	fillin_the_map(char **map, int y, int x, char **tetri);
int		backtracking(char **map, char ***tetri);
int		is_available(char **map, int y, int x, char **tetri);
void	take_off_tetri(char **map, int y, int x, char **tetri);
void	*ft_memset(void *b, int c, size_t len);
char	**first_fill(char ***tab, int nb);
#endif
