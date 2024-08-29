/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 18:04:13 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/29 18:20:30 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*sa(t_list **a)
{
	t_list	*current;
	t_list	*next;

	current = *a;
	if (!current)
		return ("");
	next = (*a)->next;
	if (!next)
		return ("");
	*a = next;
	(*a)->next = current;
	return ("sa\n");
}

char	*sb(t_list **b)
{
	t_list	*current;
	t_list	*next;

	current = *b;
	if (!current)
		return ("");
	next = (*b)->next;
	if (!next)
		return ("");
	*b = next;
	(*b)->next = current;
	return ("sb\n");
}

char	*ss(t_list **a, t_list **b)
{
	if (!sa(a))
		return ("");
	if (!sa(b))
		return ("");
	return ("ss\n");
}

char *pa(t_list **a, t_list **b)
{
	if (!*b)
		return ("");
	ft_lstadd_front(a, *b);
	ft_lstdel_front(&b);
}

void	ft_lstdel_front(t_list **lst)
{
	
}
