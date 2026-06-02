/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 02:50:26 by tthwe             #+#    #+#             */
/*   Updated: 2026/06/03 02:05:15 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <limits.h>
# include "Libft/libft.h"

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}	t_stack;

// Stack utils
int		stack_size(t_stack *stack);
t_stack	*new_node(int value);
int		is_sorted(t_stack *stack);
void	stack_add_bottom(t_stack **stack, t_stack *new);
void	free_stack(t_stack **stack);

// Algorithm helpers
t_stack	*find_max(t_stack *stack);
t_stack	*find_cheapest(t_stack *a, t_stack *b);
int		ft_max(int a, int b);
void	assign_indexes(t_stack *a);
void	rotate_to_min(t_stack **a);

// Parser
void	error_exit(t_stack *a, t_stack *b);
t_stack	*parse_args(int argc, char **argv);

// Operations
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

// Sorting
void	push_swap(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);
void	push_cheapest(t_stack **a, t_stack **b);
int		get_pos(t_stack *stack, t_stack *node);
t_stack	*find_target(t_stack *a, int val);
int		calc_cost(t_stack *a, t_stack *b, t_stack *b_node);

#endif
