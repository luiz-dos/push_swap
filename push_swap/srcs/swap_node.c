/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:00:30 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/09/11 16:38:27 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	int		len;

	len = stack_len(*stack);
	if (stack == NULL || *stack == NULL || len == 1)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	sa(t_stack **a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putstr_fd("ss\n", 1);
}
