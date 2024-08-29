/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:34:43 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/29 17:47:13 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_input(char *str)
{
	while(*str)
	{
		if (*str < '0' || *str > '9' || *str != '-' || *str != 32)
			retrun (1);
		str++;
	}
	return (0);
}

int	check_error(int ac, char **av)
{
	if (ac != 2)
		return(1);
	if (av[1][0] == '\0')
		return (1);
	if (check_input(av[1]))
		return (1);
}
