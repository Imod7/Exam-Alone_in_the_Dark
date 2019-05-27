/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fprime.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 13:02:12 by exam          #+#    #+#                 */
/*   Updated: 2019/05/27 12:45:29 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		is_prime(int n)
{
	int	i;

	i = 2;
	while (i < n)
	{
		if (n / i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		print_factors(int num, int p)
{
	while (num % p == 0 && num != p)
	{
		printf("%d*", p);
		num = num / p;
	}
	return (num);
}

int		main(int argc, char **argv)
{
	int	num;
	int p;

	if (argc != 2)
		printf("\n");
	else
	{
		num = atoi(argv[1]);
		if (num == 1)
		{
			printf("1\n");
			return (0);
		}
		p = 2;
		while (p != num && p != 20000)
		{
			if (is_prime(p) == 1)
				num = print_factors(num, p);
			p++;
		}
		printf("%d\n", num);
	}
	return (0);
}
