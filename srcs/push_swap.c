/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:56:13 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/27 12:08:43 by bepoisso         ###   ########.fr       */
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

int main(int ac, char *av[])
{
	int		*tab;
	int		size;
	t_stack	*a;
	t_stack	*b;

	// ERROR GEST
	if (ac <= 1)
		return (ft_printf("Error\nmissing arg\n"), 1);
	if (check_chars(av, ac) && ac > 2)
		return (ft_printf("Error\narguments\n"), 1);
	if (ac == 2 && check_char(av[1]))
		return (ft_printf("Error\narguments\n"), 1);
	av++;
	
	// PARSER
	if (ac != 2)
	{
		tab = parser_multarg(av, ac - 1);
		size = ac - 1;
	}
	else
		tab = parser_singlearg(av[0], &size);
	if (tab == NULL)
		return (1);
	printtab(tab, size);
	if (check_sort(tab, size))
		return (ft_printf("Error\nallready sort\n"), 1);

	// PARSER STACK
	(void)b;
	ft_printf("\n****STACK****\n");
	a = stack_parser(tab, size);
	print_stack(a);
	ft_printf("\n****MANIP****\n");
	sb(&a, 0);
	stack_index(&a);
	print_stack(a);
	return (0);
}
