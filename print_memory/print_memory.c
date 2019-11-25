/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_memory.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 09:30:06 by dsaripap      #+#    #+#                 */
/*   Updated: 2019/11/19 12:44:10 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void				puthex(unsigned char c, size_t index, char *str1)
{
	int				div;
	int				mod;
	char			*str;

	div = c / 16;
	mod = c % 16;
	str = "0123456789abcdef";
	write(1, &str[div], 1);
	write(1, &str[mod], 1);
	if (c > 32 && c < 127)
		str1[index % 16] = c;
	else
		str1[index % 16] = '.';
}

void				print_memory(const void *addr, size_t size)
{
	unsigned char	*address;
	size_t			index;
	size_t			index1;
	size_t			counter;
	char			str1[16];

	address = (unsigned char *)addr;
	index = 0;
	while (index < size)
	{
		if ((index % 2 == 0) && (index != 0) && (index % 16 != 0))
			write(1, &" ", 1);
		if ((index % 16 == 0) && (index != 0))
		{
			write(1, &" ", 1);
			write(1, str1, 16);
			if (index < size - 1)
				write(1, &"\n", 1);
		}
		puthex(address[index], index, str1);
		index++;
	}
	index1 = index % 16;
	counter = index1 + ((16 - index1) * 2);
	while ((index1 < counter) && (index1 != 0))
	{
		if ((index1 % 4 == 0) && (index1 != 0))
			write(1, &" ", 1);
		write(1, &" ", 1);
		index1 += 1;
	}
	write(1, &" ", 1);
	if ((index == size) || (index == 0))
	{
		if (index % 16 != 0)
			write(1, str1, index % 16);
		else
			write(1, str1, 16);
	}
	write(1, &"\n", 1);
}
