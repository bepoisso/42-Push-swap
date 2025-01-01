/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:56:10 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/01 15:54:05 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Décale d’une position vers le haut tous les élements de la pile a.
// Le premier élément devient le dernier.
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

// Décale d’une position vers le haut tous les élements de la pile b.
// Le premier élément devient le dernier.
void	rb(t_stack **b, int print)
{
	ra(b, 0);
	if (print)
		ft_printf("rb\n");
}

// ra et rb en même temps
void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}

// Décale d’une position vers le bas tous les élements de
// la pile a. Le dernier élément devient le premier.
void	rra(t_stack **a, int print)
{
	t_stack	*temp;

	temp = stack_last(*a);
	temp->prev->next = NULL;
	stack_add_front(a, temp);
	if (print)
		ft_printf("rra\n");
}

// écale d’une position vers le bas tous les élements de
// la pile b. Le dernier élément devient le premier.
void	rrb(t_stack **b, int print)
{
	rra(b, 0);
	if (print)
		ft_printf("rrb\n");
}
