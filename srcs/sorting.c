/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:56:15 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/27 14:59:29 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sorting(t_stack **a, t_stack **b)
{
	int	size;
	(void)b;
	
	size = stack_size(*a);

	if (size == 2)
		sa(a, 1);
}
