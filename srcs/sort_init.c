/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 16:10:49 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/01 17:45:46 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_info_a(t_stack **a, t_stack **b)
{
	stack_index(a);
	stack_index(b);
	stack_target_a(*a, *b);
	push_cost(*a, *b);
	set_cheapest(*a);
}

void	init_info_b(t_stack **a, t_stack **b)
{
	stack_index(a);
	stack_index(b);
	stack_target_b(*a, *b);
}

void	get_on_top(t_stack **stack, t_stack *top, char which)
{
	
	while (*stack != top)
	{
		if (which == 'a')
		{
			if (top->median == 1)
				rra(stack, 1);
			else
				ra(stack, 1);
		}
		else if (which == 'b')
		{
			if (top->median == 1)
				rrb(stack, 1);
			else
				rb(stack, 1);
		}
	}
}

void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*a);
	if (!cheapest)
		return ;
	if (cheapest->median && cheapest->target->median)
		rev_rotate_nodes(a, b, cheapest);
	else if (!(cheapest->median) && !(cheapest->target->median))
		rotate_nodes(a, b, cheapest);
	get_on_top(a, cheapest, 'a');
	get_on_top(b, cheapest->target, 'b');
	pb(a, b);
}

void	push_to_a(t_stack **a, t_stack **b)
{
	get_on_top(a, (*b)->target, 'a');
	pa(a, b, 1);
}
