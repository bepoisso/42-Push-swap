/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:09:52 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/01 16:10:22 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current;
	t_stack	*target;
	long	best;

	while (a)
	{
		best = LONG_MIN;
		current = b;
		while (current)
		{
			if (current->data < a->data && current->data > best)
			{
				best = current->data;
				target = current;
			}
			current = current->next;
		}
		if (best == LONG_MIN)
			a->target = find_biggest(b);
		else
			a->target = target;
		a = a->next;
	}
}

void	stack_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current;
	t_stack	*target;
	long	best;

	while (b)
	{
		best = LONG_MAX;
		current = a;
		while (current)
		{
			if (current->data > b->data && current->data < best)
			{
				best = current->data;
				target = current;
			}
			current = current->next;
		}
		if (best == LONG_MAX)
			b->target = find_lowest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	stack_index(t_stack **stack)
{
	t_stack	*current;
	int		i;
	int		median;

	if (!stack || !*stack)
		return ;
	median = stack_size(*stack) / 2;
	i = 0;
	current = *stack;
	while (current)
	{
		current->index = i;
		if (i >= median)
			current->median = 1;
		else
			current->median = 0;
		i++;
		current = current->next;
	}
}
