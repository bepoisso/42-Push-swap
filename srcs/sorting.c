/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:56:15 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/30 19:43:23 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **a)
{
	t_stack	*biggest;

	if (check_sorted(*a))
		return ;
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
	return (index);
}

int check_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return 0;
		stack = stack->next;
	}
	return 1;
}

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

	while(b)
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

void	rotate_nodes(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
		rr(a, b);
	stack_index(a);
	stack_index(b);
}

void	rev_rotate_nodes(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest && *b != cheapest->target)
		rrr(a, b);
	stack_index(a);
	stack_index(b);
}

void	get_on_top(t_stack **stack, t_stack *top, char which)
{
	while (*stack != top)
	{
		if (which == 'a')
		{
			if (top->median == 1)
				rra(stack, 1);
			else if (top->median == 0)
				ra(stack, 1);
		}
		else if (which == 'b')
		{
			if (top->median == 1)
				rrb(stack, 1);
			else if (top->median == 0)
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

void	sort_algorithm(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (--size > 3 && !check_sorted(*a))
		pb(a, b);
	if (--size > 3 && !check_sorted(*a))
		pb(a, b);
	while (size > 3 && !check_sorted(*a))
	{
		init_info_a(a, b);
		push_to_b(a, b);
		size--;
	}
	sort_three(a);
	while(*b)
	{
		init_info_b(a, b);
		push_to_a(a, b);
	}
	stack_index(a);
	min_on_top(a);
}

void	stack_free(t_stack **stack)
{
	t_stack	*current;

	current = stack_last(*stack);
	while (*stack != current)
	{
		current->next = NULL;
		current->prev = NULL;
		current->target = NULL;
		free(current);
		current = stack_last(*stack);
	}
	current->next = NULL;
	current->prev = NULL;
	current->target = NULL;
	free(current);
}

void	sorting(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sa(a, 1);
	else if (size == 3)
		sort_three(a);
	else if (size > 3)
		sort_algorithm(a, b);
	// stack_free(a);
	// stack_free(b);
}
