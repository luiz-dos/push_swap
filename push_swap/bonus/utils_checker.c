/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:58:36 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/09/11 16:39:08 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	error(t_stack **a, t_stack **b, char *line)
{
	free(line);
	free_stack(a);
	if (b)
		free_stack(b);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}

void	check_operations_two(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp("rra\n", line, 4))
		rev_rotate_stack(a);
	else if (!ft_strncmp("rrb\n", line, 4))
		rev_rotate_stack(b);
	else if (!ft_strncmp("rrr\n", line, 4))
	{
		rev_rotate_stack(a);
		rev_rotate_stack(b);
	}
	else
		error(a, b, line);
}

void	check_operations(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strncmp("pa\n", line, 3))
		push(a, b);
	else if (!ft_strncmp("pb\n", line, 3))
		push(b, a);
	else if (!ft_strncmp("sa\n", line, 3))
		swap(a);
	else if (!ft_strncmp("sb\n", line, 3))
		swap(b);
	else if (!ft_strncmp("ss\n", line, 3))
	{
		swap(a);
		swap(b);
	}
	else if (!ft_strncmp("ra\n", line, 3))
		rotate_stack(a);
	else if (!ft_strncmp("rb\n", line, 3))
		rotate_stack(b);
	else if (!ft_strncmp("rr\n", line, 3))
	{
		rotate_stack(a);
		rotate_stack(b);
	}
	else
		check_operations_two(a, b, line);
}
