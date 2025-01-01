/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:23:54 by bepoisso          #+#    #+#             */
/*   Updated: 2025/01/01 21:24:06 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//_________________Includes_________________
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

//_________________Struct_________________
typedef struct s_stack
{
	int				index;
	int				data;
	int				push_cost;
	int				median;
	int				cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

//_________________________FUNCTIONS_________________________

//_________________Error_________________
int		check_chars(char **s, int ac);
int		check_char(char *s);
int		check_sort(int *tab, int size);
int		handle_error(int ac, char **av);

//_________________Parser_________________
void	parser(int *ac, char ***av, int **tab, int *size);
int		*parser_multarg(char **s, int ac);
int		*parser_singlearg(char *s, int *size);
t_stack	*stack_parser(int *tab, int size);
void	print_stack(t_stack *stack);

//_________________Utils_________________
t_stack	*stack_new(int data);
int		stack_size(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_add_front(t_stack **stack, t_stack *new);

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
void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b);
void	rotate_nodes(t_stack **a, t_stack **b, t_stack *cheapest);
void	rev_rotate_nodes(t_stack **a, t_stack **b, t_stack *cheapest);

//_________________Sorting_________________
void	sorting(t_stack **a, t_stack **b);
void	sort_algorithm(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);

//_________________Sorting_utils_________________
t_stack	*find_biggest(t_stack *stack);
t_stack	*find_lowest(t_stack *stack);
int		check_sorted(t_stack *stack);
void	min_on_top(t_stack **a);
void	stack_free(t_stack **stack);

//_________________Sorting_target_________________
void	stack_target_a(t_stack *a, t_stack *b);
void	stack_target_b(t_stack *a, t_stack *b);
void	stack_index(t_stack **stack);

//_________________Sorting_init_________________
void	init_info_a(t_stack **a, t_stack **b);
void	init_info_b(t_stack **a, t_stack **b);
void	get_on_top(t_stack **stack, t_stack *top, char which);
void	push_to_b(t_stack **a, t_stack **b);
void	push_to_a(t_stack **a, t_stack **b);

//_________________Sorting_cost_________________
void	push_cost(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *stack);
t_stack	*find_cheapest(t_stack *stack);

#endif
