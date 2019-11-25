/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 09:27:24 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/11/19 10:03:39 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	print_memory(const void *addr, size_t size);

int		main(void)
{
	// int tab[10] = {0, 23, 150, 255, 12, 16, 42, 103};
	// int tab[14] = {0, 23, 150, 255, 83, 16, 42, 85, 98, 69, 87, 60, 110, 79};
	// int tab[15] = {0, 23, 150, 255, 83, 16, 42, 85, 98, 106, 55, 37, 116, 68, 118};
	// int tab[16] = {0, 77, 150, 35, 83, 16, 42, 85, 98, 69, 92, 37, 60, 71, 95, 102};
	int tab[17] = {0, 77, 150, 35, 83, 16, 42, 85, 98, 69, 92, 37, 60, 71, 95, 102, 81};

	print_memory(tab, sizeof(tab));
	return (0);
}