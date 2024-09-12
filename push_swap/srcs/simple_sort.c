/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:00:27 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/09/11 16:38:22 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack **stack)
{
	t_stack	*biggest;

	if (!stack || !*stack)
		return ;
	biggest = find_biggest(*stack);
	if (biggest == *stack)
		ra(stack);
	else if (biggest == (*stack)->next)
		rra(stack);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (stack_len(*a) > 3)
	{
		put_a_on_top(a, find_smallest(*a));
		pb(b, a);
	}
	simple_sort(a);
	pa(a, b);
	pa(a, b);
}
