/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:56:10 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/27 12:07:44 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	sa(t_stack **a, int print)
{
	t_stack	*temp;

	if (!*a)
		return ;
	if (stack_size(*a) < 2)
		return ;
	temp = (*a)->next;
	(*a)->next->prev = *a;
	(*a)->next = (*a)->next->next;
	stack_add_front(a, temp);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack **b, int print)
{
	sa(b, 0);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}

// void	ra(t_stack **a, int print)
// {
// 	t_stack	*temp;

// 	if (stack_size(*a) < 2)
// 		return ;
// 	temp = *a;
	
// }
