/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:56:10 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/27 14:55:51 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Intervertit les 2 premiers éléments au sommet de la pile a.
// Ne fait rien s’il n’y en a qu’un ou aucun.
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
	t_stack *temp;
	
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

// rra et rrb en même temps.
void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_printf("rrr\n");
}

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
