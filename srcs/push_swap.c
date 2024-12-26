/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:56:13 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/26 21:37:07 by bepoisso         ###   ########.fr       */
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

int	*parser_multarg(char **s, int ac)
{
	int		*tab;
	int		i;
	int		j;

	i = 0;
	if (ac <= 1)
		return (ft_printf("Error\none nbr\n"), NULL);
	tab = (int *)malloc(sizeof(int) * (ac - 1));
	while (i < ac)
	{
		j = 0;
		if (ft_atoi(s[i]) > INT_MAX || ft_atoi(s[i]) < INT_MIN)
			return (ft_printf("Error\nint size\n"), NULL);
		tab[i] = (int)ft_atoi(s[i]);
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

int	*parser_singlearg(char *s)
{
	char	**result;
	int		i;

	i = 0;
	result = ft_split(s, ' ');
	while (result[i])
		i++;
	return (parser_multarg(result, i));
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

int main(int ac, char *av[])
{
	int	*tab;

	if (ac <= 1)
		return (ft_printf("Error\nmissing arg\n"), 1);
	if (check_chars(av, ac) && ac > 2)
		return (ft_printf("Error\narguments\n"), 1);
	if (ac == 2 && check_char(av[1]))
		return (ft_printf("Error\narguments\n"), 1);
	av++;
	if (ac != 2)
		tab = parser_multarg(av, ac - 1);
	else
		tab = parser_singlearg(av[0]);
	printtab(tab, 10);
	return (0);
}
