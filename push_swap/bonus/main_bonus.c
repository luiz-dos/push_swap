/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:58:08 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/09/11 16:38:58 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	read_operations(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		check_operations(a, b, line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	if (sorted(*a) && stack_len(*b) == 0)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
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
	read_operations(&a, &b);
	free_stack(&a);
	if (b)
		free_stack(&b);
	return (0);
}
