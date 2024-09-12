/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:33:31 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/09/11 16:34:29 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

int		main(int ac, char **av);
void	read_operations(t_stack **a, t_stack **b);
void	check_operations(t_stack **a, t_stack **b, char *line);
void	check_operations_two(t_stack **a, t_stack **b, char *line);
void	error(t_stack **a, t_stack **b, char *line);

#endif /* CHECKER_BONUS_H */
