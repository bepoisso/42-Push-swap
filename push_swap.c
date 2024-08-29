/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:34:43 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/29 18:04:08 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_to_list(char *str, t_list **stack)
{
	t_list	*new;
	char	**strs;
	int		i;

	i = 0;
	strs = ft_split(str, ' ');
	while (strs[i])
	{
		new = ft_lstnew(ft_atoi(strs[i]));
		ft_lstadd_back(stack, new);
		free(new);
		i++;
	}
}

char *push_swap(char *str)
{
	t_list	*a;
	t_list	*b;

	a = malloc(sizeof(a));
	b = malloc(sizeof(b));
	if (!a || !b)
		return (NULL);
	split_to_list(str, &a);
}
