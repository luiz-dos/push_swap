/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_av.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:58:53 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/09/11 16:36:58 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	only_space_av(char *str)
{
	int i;

	i = 0;
	while(str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	check_duplicate(t_stack *stack, long nbr)
{
	t_stack	*current;

	if (stack == NULL)
		return (0);
	current = stack;
	while (current)
	{
		if (current->value == (int)nbr)
			return (1);
		current = current->next;
	}
	return (0);
}

int	non_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_av(char *av, long nbr)
{
	if (non_numeric(av))
		return (1);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (1);
	return (0);
}
