/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   brainfuck.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: exam <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/21 15:42:32 by exam          #+#    #+#                 */
/*   Updated: 2019/05/22 16:30:41 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int			find_openbr(char *s, int i)
{
	int 	flag;

	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ']')	
			flag++;
		if (s[i] == '[' && flag != 0)
			flag--; 
		if (s[i] == '[' && flag == 0)
			return (i);
		i--;
	}
	return (i);
}

int			find_closebr(char *s, int i)
{
	int 	flag;

	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '[')	
			flag++;
		if (s[i] == ']' && flag != 0)
			flag--; 
		if (s[i] == ']' && flag == 0)
			return (i);
		i++;
	}
	return (i);
}

int			main(int argc, char **argv)
{
	char	str[2048];
	int		i;
	int		j;
	int		open_br;
	int		close_br;

	open_br = 0;
	close_br = 0;
	i = 0;
	while (i < 2048)
	{
		str[i] = 0;
		i++;
	}
	if (argc == 2)
	{
		i = 0;
		j = 0;
		while (argv[1][i] != '\0')
		{
			if (argv[1][i] == '+')
			{	
				str[j]++;
				i++;
			}
			else if (argv[1][i] == '-')
			{
				str[j]--;
				i++;
			}
			else if (argv[1][i] == '>')
			{
				j++;
				i++;
			}
			else if (argv[1][i] == '<')
			{
				j--;
				i++;
			}
			else if (argv[1][i] == '[' && str[j] == 0)
			{
				close_br = find_closebr(argv[1], i);
				while (i < close_br)
				{
					i++;
				}
			}
			else if (argv[1][i] == ']' && str[j] != 0)
			{
				open_br = find_openbr(argv[1], i);
				while (i > open_br)
					i--;
			}
			else if (argv[1][i] == '.')
			{
				write(1, &str[j], 1);
				i++;
			}
			else
				i++;
		}
		//str[len] = '\0';
	}
	else
		write(1, "\n", 1);
	return (0);
}
