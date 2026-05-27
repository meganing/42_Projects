/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tthwe <tthwe@student.42bangkok.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 02:50:26 by tthwe             #+#    #+#             */
/*   Updated: 2026/05/28 02:50:26 by tthwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
** Sorts exactly 3 elements in stack a. Uses hardcoded optimal moves
** for each of the 6 possible orderings (identified by which position
** holds the minimum index).
**
** Cases visualized (top → bottom), where 0=min, 1=mid, 2=max:
**   [0,1,2] → done          [1,0,2] → sa
**   [2,0,1] → ra            [1,2,0] → rra
**   [0,2,1] → rra+sa        [2,1,0] → sa+rra
*/
void	sort_3(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->index;
	mid = (*a)->next->index;
	bot = (*a)->next->next->index;
	if (top < mid && mid < bot)
		return ;
	if (top < mid && top < bot)
	{
		rra(a);
		sa(a);
	}
	else if (mid < top && mid < bot)
	{
		if (top > bot)
			ra(a);
		else
			sa(a);
	}
	else
	{
		if (top > mid)
		{
			sa(a);
			rra(a);
		}
		else
			rra(a);
	}
}
