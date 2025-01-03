/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:56:13 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/01 21:24:16 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	int		*tab;
	int		size;
	t_stack	*a;
	t_stack	*b;

	if (handle_error(ac, av))
		return (1);
	av++;
	parser(&ac, &av, &tab, &size);
	if (tab == NULL)
		return (1);
	a = stack_parser(tab, size);
	b = NULL;
	free(tab);
	sorting(&a, &b);
	free(a);
	free(b);
	return (0);
}
