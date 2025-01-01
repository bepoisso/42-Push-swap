/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:06:42 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/01 17:07:17 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	return (index);
}

int	check_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	min_on_top(t_stack **a)
{
	t_stack	*min;

	min = find_lowest(*a);
	while (min != *a)
	{
		if (min->median)
			rra(a, 1);
		else
			ra(a, 1);
	}
}

void	stack_free(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
