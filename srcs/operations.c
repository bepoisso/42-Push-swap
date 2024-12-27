/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:56:10 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/27 13:03:18 by bepoisso         ###   ########.fr       */
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

void	ra(t_stack **a, int print)
{
	t_stack	*temp;

	if (stack_size(*a) < 2)
		return ;
	temp = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	stack_add_back(a, temp);
	if (print)
		ft_printf("ra\n");
}

void	rb(t_stack **b, int print)
{
	ra(b, 0);
	if (print)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}

void	rra(t_stack **a, int print)
{
	t_stack *temp;
	
	temp = stack_last(*a);
	temp->prev->next = NULL;
	stack_add_front(a, temp);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, int print)
{
	rra(b, 0);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_printf("rrr\n");
}

void	pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;

	temp = *b;
	*b = (*b)->next;
	stack_add_front(a, temp);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	pa(b, a, 0);
	ft_printf("pb\n");
}
