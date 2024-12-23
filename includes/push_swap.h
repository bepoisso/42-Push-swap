/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:23:54 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/19 13:35:40 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

//_________________Includes_________________
# include "libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>

//_________________Struct_________________
typedef struct s_lst
{
	int				data;
	struct s_data	*next;
	struct s_data	*prev;
}	t_lst;

//_________________Function_________________


#endif
