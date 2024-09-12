/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luiz-dos <luiz-dos@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 16:35:16 by luiz-dos          #+#    #+#             */
/*   Updated: 2024/09/11 16:35:17 by luiz-dos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_middle;
	bool			cheapest;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target_node;
}					t_stack;

int					main(int ac, char **av);
void				main_two(t_stack **a, t_stack **b);
void				init_stack(t_stack **stack, char **av, bool flag_av);
int					check_duplicate(t_stack *a, long nbr);
void				handle_error(t_stack **stack, char **av, bool flag_av);
void				free_stack(t_stack **stack);
void				free_av(char **av);
void				append_node(t_stack **a, int nbr);
void				init_node(t_stack *node, int nbr);
t_stack				*find_last_node(t_stack *a);
int					sorted(t_stack *stack);
int					stack_len(t_stack *stack);
void				swap(t_stack **stack);
void				sa(t_stack **a);
void				sb(t_stack **b);
void				ss(t_stack **a, t_stack **b);
void				simple_sort(t_stack **stack);
t_stack				*find_biggest(t_stack *stack);
t_stack				*find_smallest(t_stack *stack);
void				rev_rotate_stack(t_stack **stack);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				rotate_stack(t_stack **a);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
long				ft_atol(const char *nptr);
int					check_av(char *av, long nbr);
int					non_numeric(char *str);
void				push(t_stack **dest, t_stack **src);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **b, t_stack **a);
void				sort_five(t_stack **a, t_stack **b);
void				hard_sort(t_stack **a, t_stack **b);
void				set_nodes(t_stack *a, t_stack *b);
void				set_index(t_stack *stack);
void				set_target(t_stack *a, t_stack *b);
void				set_cost(t_stack *a, t_stack *b);
void				set_cheapest(t_stack *stack);
t_stack				*find_cheapest(t_stack *stack);
void				move_nodes(t_stack **a, t_stack **b);
void				put_a_on_top(t_stack **stack, t_stack *node);
void				put_b_on_top(t_stack **stack, t_stack *node);
void				smallest_on_top(t_stack **a);

#endif /* PUSH_SWAP_H */
