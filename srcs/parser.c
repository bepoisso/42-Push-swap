/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:15:40 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/01 18:15:28 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*parser_multarg(char **s, int ac)
{
	int		*tab;
	int		i;
	int		j;

	i = 0;
	if (ac <= 1)
		return (ft_printf("Error\none nbr\n"), NULL);
	tab = (int *)malloc(sizeof(int) * (ac));
	while (i < ac)
	{
		j = 0;
		if (ft_atoi(s[i]) > INT_MAX || ft_atoi(s[i]) < INT_MIN)
			return (free(tab), ft_printf("Error\nint size\n"), NULL);
		tab[i] = (int)ft_atoi(s[i]);
		while (j < i)
		{
			if (tab[j] == tab[i])
				return (free(tab), ft_printf("Error\ndouble\n"), NULL);
			j++;
		}
		i++;
	}
	return (tab);
}

int	*parser_singlearg(char *s, int *size)
{
	char	**result;
	int		*tab;

	*size = 0;
	result = ft_split(s, ' ');
	while (result[*size])
		(*size)++;
	tab = parser_multarg(result, *size);
	free_2d(result);
	return (tab);
}

t_stack	*stack_parser(int *tab, int size)
{
	t_stack	*new;
	t_stack	*stack;
	int		i;

	i = 0;
	stack = NULL;
	while (i < size)
	{
		new = stack_new(tab[i]);
		stack_add_back(&stack, new);
		i++;
	}
	return (stack);
}

void	print_stack(t_stack *stack)
{
	ft_printf("\n----Stack----\n");
	while (stack)
	{
		ft_printf("index:%d data:%d ptr:%p next:%p prev:%p\n", stack->index, stack->data, stack, stack->next, stack->prev);
		stack = stack->next;
	}
	ft_printf("-------------\n");
}
