/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:23:54 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/26 19:50:07 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

//_________________Includes_________________
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

//_________________Struct_________________
typedef struct s_lst
{
	int				data;
	struct s_data	*next;
	struct s_data	*prev;
}	t_lst;

//_________________Function_________________
int	check_chars(char **s, int ac);
int	check_char(char *s);
int	*parser_multarg(char **av, int ac);

//_________________Temp_________________
void	printtab(int *tab, int	size);

#endif
