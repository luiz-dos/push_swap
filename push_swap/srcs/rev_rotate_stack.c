/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:00:15 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/09/11 16:38:01 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_stack(t_stack **stack)
{
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack **a)
{
	rev_rotate_stack(a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b)
{
	rev_rotate_stack(b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	rev_rotate_stack(a);
	rev_rotate_stack(b);
	ft_putstr_fd("rrr\n", 1);
}
