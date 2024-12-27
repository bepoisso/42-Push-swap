/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:56:15 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/27 17:15:07 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_tree(t_stack **a)
{
	t_stack	*biggest;
	
	biggest = find_biggest(*a);
	if (biggest == *a)
		ra(a, 1);
	else if ((*a)->next == biggest)
		rra(a, 1);
	if ((*a)->data > (*a)->next->data)
		sa(a, 1);
}


t_stack	*find_biggest(t_stack *stack)
{
	int		biggest;
	t_stack	*index;

	if (!stack)
		return (NULL);
	biggest = stack->data;
	index = stack;
	while (stack)
	{
		if (stack->data > biggest)
		{
			biggest = stack->data;
			index = stack;
		}
		stack = stack->next;
	}
	return (index);
}

t_stack	*find_lowest(t_stack *stack)
{
	int		lowest;
	t_stack	*index;

	if (!stack)
		return (NULL);
	lowest = stack->data;
	index = stack;
	while (stack)
	{
		if (stack->data < lowest)
		{
			lowest = stack->data;
			index = stack;
		}
		stack = stack->next;
	}
	retrun (index);
}

int	check_sorted(t_stack *stack)
{
	int	nbr;

	nbr = stack->data;
	while (stack)
	{
		if (stack->data < nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	stack_init(t_stack **a, t_stack **b)
{
	stack_index(a);
	stack_index(b);
}

void	sort_algorithm(t_stack **a, t_stack **b)
{
	int	size_a;

	size_a = stack_size(*a);
	if (size_a-- > 3 && !check_sorted(*a));
		pb(a, b);
	if (size_a-- > 3 && !check_sorted(*a));
		pb(a, b);
	while (size_a-- > 3 && !check_sorted(*a))
	{
		
	}
}

void	sorting(t_stack **a, t_stack **b)
{
	int	size;
	(void)b;
	
	size = stack_size(*a);
	if (size == 2)
		sa(a, 1);
	else if (size == 3)
		sort_tree(a);
	// else if (size > 3)
	// 	sort_algorithm(a, b);
}
