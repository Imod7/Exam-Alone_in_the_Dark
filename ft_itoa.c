/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 14:12:46 by exam          #+#    #+#                 */
/*   Updated: 2019/05/21 21:33:52 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			count_digits(long nbr)
{
	int		digits;

	digits = 1;
	if (nbr < 0)
		nbr = nbr * (-1);
	while (nbr / 10 != 0)
	{
		nbr = nbr / 10;
		digits++;
	}
	return (digits);
}

char		*ft_itoa(int nbr)
{
	char	*string;
	int		len;
	int		flag;
	int		j;
	long	lnum;

	lnum = nbr;
	flag = 0;
	len = count_digits(lnum);
	j = len;
	if (lnum < 0)
	{
		lnum = lnum * (-1);
		len++;
		flag = 1;
		j = len - 1;
	}
	string = (char *)malloc(sizeof(char) * (len + 1));
	string[len] = '\0';
	if (flag == 1)
		string[0] = 45;
	while (j > 0)
	{
		string[len - 1] = (lnum % 10) + 48;
		lnum = lnum / 10;
		len--;
		j--;
	}
	return (string);
}
