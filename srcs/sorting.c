/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:56:15 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/28 20:07:54 by bepoisso         ###   ########.fr       */
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

void	a_get_your_target(t_stack *node, t_stack **b)
{
	t_stack	*current;
	t_stack	*closest;
	long	min_diff;
	long	diff;

	current = *b;
	closest = NULL;
	min_diff = LONG_MAX;
	while (current)
	{
		if (current->data < node->data)
		{
			diff = node->data - current->data;
			if (diff < min_diff)
			{
				min_diff = diff;
				closest = current;
			}
		}
		current = current->next;
	}
	if (!closest)
		node->target = find_biggest(*b);
	node->target = closest;
}

void	init_target(t_stack **a, t_stack **b)
{
	t_stack	*current;

	current = *a;
	while (current)
	{
		a_get_your_target(current, b);
		current = current->next;
	}
	
}

void	push_coast(t_stack **a, t_stack **b)
{
	// A faire bon courage j'ai la flemme

	// Trouver le node la moins chere a push
			// /!\ On ne compte pas le pb() dans les mouve
			// la formule :		x mouve pour envoyer en top a
			// 				+	x mouve pour envoyer la node au dessus de la target
			//				=	Push cost
			// si on trouve un push cost de 0 on s'arrete par ce que rien ne peut etre en dessous
			// exemple pour push	25 = 0 (pb) (A PAS TROP PRENDRE EN COMPTE)
			// 						-38 = 1 (pb + rrb) (on mets 99 en haut et on push)
			// 						10 = 1 (ss + pb) (10 doit etre au desus de 0 donc on ss puis pb)
			// 						7 = 3 (sb + rra + rra  + pb)
			// 						42 = 1 (rra + pb)
}

void	sort_algorithm(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a) + 1;
	if (--size > 3 && !check_sorted(*a))
		pb(a, b);
	if (--size > 3 && !check_sorted(*a))
		pb(a, b);
	while (size > 3 /* && !check_sorted(*a) */)
	{
		init_target(a, b);
		push_coast(a, b);
		size--;
	}
	sort_three(a);
	while(*b)
	{
		// push toutes les node b dans la stack a
	// On calcule la target de chaque node b
		// la target est le nombre le plus grand et le plus prets
	// On push la node au dessus de ca target
		// si la target est au dessus de la mediane
			// on rotate (ra) jusqua avoir la target en haut
		// si la target est en dessuous de la mediane
			// on revers rotate (rra) jusqua avoir la target en haut
	}
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
}
