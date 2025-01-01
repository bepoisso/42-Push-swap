/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:53:12 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/01 18:27:09 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Intervertit les 2 premiers éléments au sommet de la pile a.
// Ne fait rien s’il n’y en a qu’un ou aucun.
void	sa(t_stack **a, int print)
{
	if (!*a)
		return ;
	if (stack_size(*a) < 2)
		return ;
	*a = (*a)->next;
	(*a)->prev->prev = *a;
	(*a)->prev->next = (*a)->next;
	if ((*a)->next)
		(*a)->next->prev = (*a)->prev;
	(*a)->next = (*a)->prev;
	(*a)->prev = NULL;
	if (print)
		ft_printf("sa\n");
}

// Intervertit les 2 premiers éléments au sommet de la pile b.
// Ne fait rien s’il n’y en a qu’un ou aucun.
void	sb(t_stack **b, int print)
{
	sa(b, 0);
	if (print)
		ft_printf("sb\n");
}

// sa et sb en même temps
void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}
