/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:56:15 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/28 12:29:49 by bepoisso         ###   ########.fr       */
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

void	best_score(t_stack **a, t_stack **b, long long result)
{
	t_stack	*second;
	t_stack	*bottom;
	

	(*a)->score = ft_abs((*a)->data - result);
	second = (*a)->next;
	second->score = ft_abs(second->data - result);
	bottom = stack_last(*a);
	bottom->score = ft_abs(bottom->data - result);
	if ((*a)->score < second->score && (*a)->score < bottom->score)
		pb(a, b);
	else if (second->score < (*a)->score && second->score < bottom->score)
	{
		sa(a, 1);
		pb(a, b);
	}
	else if (bottom->score < second->score && bottom->score < (*a)->score)
	{
		rra(a, 1);
		pb(a, b);
	}
}

void	stack_init(t_stack **a, t_stack **b)
{
	t_stack	*current;
	
	current = *a;
	stack_index(a);
	stack_index(b);
	while(current)
	{
		current->target = *b;
		current = current->next;
	}
}

void	push_median(t_stack **a, t_stack **b)
{
	long long	result;
	int			size;
	t_stack		*current;

	result = 0;
	size = stack_size(*a);
	current = *a;
	while (current)
	{
		result += current->data;
		current = current->next;
	}
	result /= size;
	best_score(a, b, result);
}

void	sort_algorithm(t_stack **a, t_stack **b)
{
	int	size_a;

	size_a = stack_size(*a);
	if (size_a-- > 3 && !check_sorted(*a))
		pb(a, b);
	size_a = stack_size(*a);
	stack_init(a, b);
	while(size_a >= 0)
	{
		if ((*a)->data < (*a)->target->data)
		{
			pb(a, b);
			rb(b, 1);
		}
		else
			pb(a, b);
		size_a = stack_size(*a);
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
	else if (size > 3)
		sort_algorithm(a, b);
}
