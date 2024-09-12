/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:59:09 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/09/11 16:37:08 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_av(char **av)
{
	int	i;

	i = 0;
	if (av == NULL || *av == NULL)
		return ;
	while (av[i])
		free(av[i++]);
	free(av);
}

void	free_stack(t_stack **stack)
{
	t_stack	*next_node;
	t_stack	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*stack = NULL;
}

void	handle_error(t_stack **stack, char **av, bool flag_av)
{
	free_stack(stack);
	if (flag_av)
		free_av(av);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}
