/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nodes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:00:23 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/09/12 12:26:13 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack)
{
	int	i;
	int	middle;

	if (!stack)
		return ;
	i = 0;
	middle = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= middle)
			stack->above_middle = true;
		else
			stack->above_middle = false;
		stack = stack->next;
		i++;
	}
}

void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*best_target;
	long	best_value;

	while (b)
	{
		best_value = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < best_value)
			{
				best_value = current_a->value;
				best_target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_value == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = best_target;
		b = b->next;
	}
}

void	set_cost(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->push_cost = b->index;
		if (!b->above_middle)
			b->push_cost = len_b - b->index;
		if (b->target_node->above_middle)
			b->push_cost += b->target_node->index;
		else
			b->push_cost += len_a - b->target_node->index;
		b = b->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;
	long	cheapest_value;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	set_nodes(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target(a, b);
	set_cost(a, b);
	set_cheapest(b);
}
