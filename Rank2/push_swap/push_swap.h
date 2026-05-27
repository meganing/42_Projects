/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 02:50:26 by tthwe             #+#    #+#             */
/*   Updated: 2026/05/28 04:17:18 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
void	rotate_min_to_top(t_stack **a);
void	assign_index(t_stack *stack);
void	sort_3(t_stack **a);

int		ft_atoi_check(const char *str, int *result);
void	free_stack(t_stack **stack);
void	free_n_exit(t_stack **stack);
void	ft_stack_add_bottom(t_stack **stack, int data);
int		has_duplicate(t_stack *stack, int data);

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

#endif