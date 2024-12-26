/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:56:13 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/26 19:58:59 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_chars(char **s, int ac)
{
	int	i;
	int	j;

	j = 1;
	while (j < ac)
	{
		i = 0;
		while (s[j][i])
		{
			if ((s[j][i] < '0' || s[j][i] > '9') && s[j][i] != '-')
				return (1);
			i++;
		}
		j++;
	}
	
	return (0);
}

int	check_char(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != '-' && s[i] != ' ')
				return (1);
			i++;
	}
	return (0);
}

int	*parser_multarg(char **av, int ac)
{
	int		*tab;
	int		i;
	int		j;

	i = 0;
	tab = (int *)malloc(sizeof(int) * (ac - 1));
	while (i < ac - 1)
	{
		j = 0;
		if (ft_atoi(av[i + 1]) > INT_MAX || ft_atoi(av[i + 1]) < INT_MIN)
			return (ft_printf("Error\nint size\n"), NULL);
		tab[i] = (int)ft_atoi(av[i + 1]);
		while (j < i)
		{
			if (tab[j] == tab[i])
				return (ft_printf("Error\ndouble\n"), NULL);
			j++;
		}
		i++;
	}
	return (tab);
}

void	printtab(int *tab, int	size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d\n", tab[i]);
		i++;
	}
}

int main(int argc, char *argv[])
{
	int	*tab;

	if (argc <= 1)
		return (ft_printf("Error\nmissing arg\n"), 1);
	if (check_chars(argv, argc) && argc > 2)
		return (ft_printf("Error\narguments\n"), 1);
	if (argc == 2 && check_char(argv[1]))
		return (ft_printf("Error\narguments\n"), 1);
	tab = parser_multarg(argv, argc);
	printtab(tab, argc - 1);
	return (0);
}
