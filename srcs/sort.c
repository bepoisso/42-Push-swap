/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:56:15 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/01 18:52:26 by bepoisso         ###   ########.fr       */
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

void	sort_algorithm(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size > 3 && !check_sorted(*a))
	{
		pb(a, b);
		size--;
	}
	if (size > 3 && !check_sorted(*a))
		pb(a, b);
	while (size > 3 && !check_sorted(*a))
	{
		init_info_a(a, b);
		push_to_b(a, b);
		size = stack_size(*a);
	}
	sort_three(a);
	while (*b)
	{
		init_info_b(a, b);
		push_to_a(a, b);
	}
	stack_index(a);
	min_on_top(a);
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
	stack_free(a);
	stack_free(b);
}
