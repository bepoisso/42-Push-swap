/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:23:54 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/27 11:00:59 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

//_________________Includes_________________
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

//_________________Function_________________
typedef struct s_stack
{
	int		data;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//_________________Function_________________
int	check_chars(char **s, int ac);
int	check_char(char *s);
int	*parser_multarg(char **av, int ac);
int	*parser_singlearg(char *s, int *size);
t_stack	*stack_parser(int *tab, int size);

//_________________Stack_manip_________________
t_stack	*stack_new(int data);
int	stack_size(t_stack *stack);
t_stack *stack_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_add_front(t_stack **stack, t_stack *new);

//_________________Temp_________________
void	printtab(int *tab, int	size);
void	print_stack(t_stack *stack);

#endif
