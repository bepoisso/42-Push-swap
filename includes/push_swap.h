/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:23:54 by bepoisso          #+#    #+#             */
/*   Updated: 2024/12/27 17:04:49 by bepoisso         ###   ########.fr       */
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
	int		index;
	int		data;
	int		push_cost;
	int		above_median;
	int		cheapest;
	struct s_stack	*target;
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
int		stack_size(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_add_front(t_stack **stack, t_stack *new);
void	stack_index(t_stack **stack);

//_________________Operation_________________
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b);

//_________________Sorting_________________
void	sorting(t_stack **a, t_stack **b);
void	sort_tree(t_stack **a);
t_stack	*find_biggest(t_stack *stack);
t_stack	*find_lowest(t_stack *stack);
int		check_sorted(t_stack *stack);


//_________________Temp_________________
void	printtab(int *tab, int	size);
void	print_stack(t_stack *stack);

#endif
