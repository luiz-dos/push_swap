/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:59:23 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/09/11 16:37:29 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_two(t_stack **a, t_stack **b)
{
	if (stack_len(*a) == 2)
		sa(a);
	else if (stack_len(*a) == 3)
		simple_sort(a);
	else if (stack_len(*a) == 5)
		sort_five(a, b);
	else
		hard_sort(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	bool	flag_av;

	a = NULL;
	b = NULL;
	flag_av = false;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
	{
		flag_av = true;
		av = ft_split(av[1], ' ');
		init_stack(&a, av, flag_av);
	}
	else
		init_stack(&a, av + 1, flag_av);
	if (!sorted(a))
		main_two(&a, &b);
	free_stack(&a);
	return (0);
}
