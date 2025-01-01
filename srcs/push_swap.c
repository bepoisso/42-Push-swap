/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:56:13 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/01 19:18:49 by bepoisso         ###   ########.fr       */
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
	if (ac != 2)
	{
		tab = parser_multarg(av, ac - 1);
		size = ac - 1;
	}
	else
		tab = parser_singlearg(av[0], &size);
	if (tab == NULL)
		return (1);
	if (check_sort(tab, size))
		return (free(tab), 0);
	a = stack_parser(tab, size);
	free(tab);
	sorting(&a, &b);
	free(a);
	free(b);
	return (0);
}
