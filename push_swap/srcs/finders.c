/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:58:57 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/09/11 16:37:02 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last_node(t_stack *stack)
{
	t_stack	*current;

	if (stack == NULL)
		return (NULL);
	current = stack;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

t_stack	*find_biggest(t_stack *stack)
{
	t_stack	*biggest;
	int		nbr;

	if (!stack)
		return (NULL);
	biggest = NULL;
	nbr = INT_MIN;
	while (stack)
	{
		if (stack->value > nbr)
		{
			nbr = stack->value;
			biggest = stack;
		}
		stack = stack->next;
	}
	return (biggest);
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*smallest;
	long	nbr;

	if (!stack)
		return (NULL);
	smallest = NULL;
	nbr = LONG_MAX;
	while (stack)
	{
		if (stack->value < nbr)
		{
			nbr = stack->value;
			smallest = stack;
		}
		stack = stack->next;
	}
	return (smallest);
}

t_stack	*find_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
