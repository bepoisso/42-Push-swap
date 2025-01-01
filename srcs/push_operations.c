/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:51:44 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/01 15:52:53 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Prend le premier élément au sommet de b et le met sur a.
// Ne fait rien si b est vide.
void	pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;

	temp = *b;
	*b = (*b)->next;
	stack_add_front(a, temp);
	if (print)
		ft_printf("pa\n");
}

// Prend le premier élément au sommet de a et le met sur b.
// Ne fait rien si a est vide.
void	pb(t_stack **a, t_stack **b)
{
	pa(b, a, 0);
	ft_printf("pb\n");
}
