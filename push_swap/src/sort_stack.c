/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:23:45 by ntalmon           #+#    #+#             */
/*   Updated: 2024/01/22 15:20:27 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_node **stack)
{
	t_node	*max_nbr;

	max_nbr = find_max(*stack);
	if (*stack == max_nbr)
		rotate_a(stack);
	else if ((*stack)->next == max_nbr)
		rotate_r_a(stack);
	if ((*stack)->nbr > (*stack)->next->nbr)
		swap_a(stack);
}

void	sort_stacks(t_node **a_list, t_node **b_list)
{
	int	len_a;

	len_a = stack_size(*a_list);
	if (len_a-- > 3 && !list_a_sorted(*a_list))
		pb(a_list, b_list);
	if (len_a-- > 3 && !list_a_sorted(*a_list))
		pb(a_list, b_list);
	while (len_a-- > 3 && !list_a_sorted(*a_list))
	{
		init_nodes_a(*a_list, *b_list);
		move_a_to_b(a_list, b_list);
	}
	sort_three(a_list);
	while (*b_list)
	{
		init_nodes_b(*a_list, *b_list);
		move_b_to_a(a_list, b_list);
	}
	current_index(*a_list);
	min_on_top(a_list);
}
