/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:23:54 by bepoisso          #+#    #+#             */
/*   Updated: 2024/08/29 17:53:15 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int		value;
	void	*prev;
	void	*next;
}	t_list;

int	check_error(int ac, char **av);

#endif
