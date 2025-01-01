/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:08:46 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/01 16:13:11 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_cost(t_stack *a, t_stack *b)
{
	int	size_b;
	int	size_a;

	size_b = stack_size(b);
	size_a = stack_size(a);
	while (a)
	{
		a->push_cost = a->index;
		if (a->median)
			a->push_cost = size_a - a->index;
		if (!(a->target->median))
			a->push_cost += a->target->index;
		else
			a->push_cost += size_b - a->target->index;
		a = a->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	t_stack	*cheapest;
	long	value;

	if (!stack)
		return ;
	value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < value)
		{
			value = stack->push_cost;
			stack->cheapest = 0;
			cheapest = stack;
		}
		stack = stack->next;
	}
	cheapest->cheapest = 1;
}

t_stack	*find_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
