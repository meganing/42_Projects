/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 03:26:57 by tthwe             #+#    #+#             */
/*   Updated: 2026/05/28 04:29:46 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	free_n_exit(t_stack **stack)
{
	free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}

static t_stack	*ft_new_node(int data)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = data;
	node->index = 0;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void	ft_stack_add_bottom(t_stack **stack, int data)
{
	t_stack	*new;
	t_stack	*last;

	new = ft_new_node(data);
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

int	has_duplicate(t_stack *stack, int data)
{
	while (stack)
	{
		if (stack->data == data)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	int		nbr;
	int		i;

	stack_a = NULL;
	if (ac == 1)
		return (0);
	i = 1;
	while (i < ac)
	{
		if (!ft_atoi_check(av[i], &nbr))
			free_n_exit(&stack_a);
		if (has_duplicate(stack_a, nbr))
			free_n_exit(&stack_a);
		ft_stack_add_bottom(&stack_a, nbr);
		i++;
	}
	free_stack(&stack_a);
	return (0);
}
