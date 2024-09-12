/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:59:18 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/09/11 16:37:24 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_node(t_stack *node, int nbr)
{
	node->value = nbr;
	node->index = 0;
	node->push_cost = 0;
	node->above_middle = false;
	node->cheapest = false;
	node->next = NULL;
	node->prev = NULL;
	node->target_node = NULL;
}

void	append_node(t_stack **stack, int nbr)
{
	t_stack	*node;
	t_stack	*last_node;

	if (stack == NULL)
		return ;
	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return ;
	init_node(node, nbr);
	if (*stack == NULL)
		*stack = node;
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_stack(t_stack **stack, char **av, bool flag_av)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		nbr = ft_atol(av[i]);
		if (check_av(av[i], nbr))
			handle_error(stack, av, flag_av);
		if (check_duplicate(*stack, nbr))
			handle_error(stack, av, flag_av);
		append_node(stack, nbr);
		i++;
	}
	if (flag_av)
		free_av(av);
}
