/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhamdi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 10:16:23 by bhamdi            #+#    #+#             */
/*   Updated: 2017/03/26 15:26:30 by bhamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memalloc(size_t size)
{
	char	*zone;
	size_t	i;

	i = 0;
	if (!(zone = (char*)malloc(size)))
		return (NULL);
	while (i < size)
		zone[i++] = 0;
	return (zone);
}
