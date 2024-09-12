/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:59:26 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/09/11 16:37:43 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_b_on_top(t_stack **stack, t_stack *node)
{
	if (!stack)
		return ;
	set_index(*stack);
	while (*stack != node)
	{
		if (node->above_middle)
			rb(stack);
		else
			rrb(stack);
	}
}

void	put_a_on_top(t_stack **stack, t_stack *node)
{
	if (!stack)
		return ;
	set_index(*stack);
	while (*stack != node)
	{
		if (node->above_middle)
			ra(stack);
		else
			rra(stack);
	}
}

void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = find_cheapest(*b);
	if (cheapest_node->above_middle && cheapest_node->target_node->above_middle)
	{
		while (*a != cheapest_node->target_node && *b != cheapest_node)
			rr(a, b);
	}
	else if (!(cheapest_node->above_middle)
		&& !(cheapest_node->target_node->above_middle))
	{
		while (*a != cheapest_node->target_node && *b != cheapest_node)
			rrr(a, b);
	}
	put_b_on_top(b, cheapest_node);
	put_a_on_top(a, cheapest_node->target_node);
	pa(a, b);
}
