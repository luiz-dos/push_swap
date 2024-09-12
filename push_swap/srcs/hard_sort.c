/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:59:13 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/09/12 13:00:23 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smallest_on_top(t_stack **a)
{
	t_stack	*smallest;

	if (!a)
		return ;
	smallest = find_smallest(*a);
	if (smallest->above_middle)
	{
		while (*a != smallest)
			ra(a);
	}
	else
	{
		while (*a != smallest)
			rra(a);
	}
}

void	hard_sort(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	while (len_a-- > 3)
		pb(b, a);
	simple_sort(a);
	while (*b)
	{
		set_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_index(*a);
	smallest_on_top(a);
}
