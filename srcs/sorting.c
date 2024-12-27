/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:56:15 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/27 18:59:18 by bepoisso         ###   ########.fr       */
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

void	best_score(t_stack **a, t_stack **b)
{
	t_stack	*top;
	t_stack *bottom;
	long	score;

	top = *b;
	bottom = stack_last(*b);
	score = ft_abs((*a)->data - top->data);	
	if (ft_abs((*a)->data - bottom->data) < score)
	{
		pb(a, b);
		rb(b, 1);
	}
	else
		pb(a, b);
}

void	stack_init(t_stack **a, t_stack **b)
{
	stack_index(a);
	stack_index(b);
}

void	sort_algorithm(t_stack **a, t_stack **b)
{
	int	size_a;
	int	size_b;

	size_a = stack_size(*a);
	if (size_a-- > 3 && !check_sorted(*a))
		pb(a, b);
	if (size_a-- > 3 && !check_sorted(*a))
		pb(a, b);
	if (check_sorted(*b))
		sb(b, 1);
	while(!check_sorted(*a))
	{
		while (size_a > 3 && !check_sorted(*a))
		{
			best_score(a, b);
			size_a = stack_size(*a);
		}
		size_b = stack_size(*b);
		ft_printf("ICCCCCI");
		int i = 0;
		while (size_b > 0 && !check_sorted(*a))
		{
			best_score(b, a);
			size_b = stack_size(*b);
			if (i > 999)
				break ;
			i++;
		}
		if (i > 999)
			break ;
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
