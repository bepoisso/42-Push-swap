/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:58:53 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/01 16:33:03 by bepoisso         ###   ########.fr       */
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

int	check_sort(int *tab, int size)
{
	int	i;

	i = 0;
	while (i + 1 < size)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	handle_error(int ac, char **av)
{
	if (ac <= 1)
		return (ft_printf("Error\nmissing arg\n"), 1);
	if (check_chars(av, ac) && ac > 2)
		return (ft_printf("Error\narguments\n"), 1);
	if (ac == 2 && check_char(av[1]))
		return (ft_printf("Error\narguments\n"), 1);
	return (0);
}
