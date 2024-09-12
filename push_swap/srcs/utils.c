/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:00:35 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/09/11 16:38:32 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	t_stack	*current;
	int		count;

	if (stack == NULL)
		return (0);
	current = stack;
	count = 0;
	while (current)
	{
		current = current->next;
		count++;
	}
	return (count);
}

int	sorted(t_stack *stack)
{
	t_stack	*current;

	if (stack == NULL)
		return (1);
	current = stack;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
