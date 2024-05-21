/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:20:00 by ntalmon           #+#    #+#             */
/*   Updated: 2024/01/23 11:35:52 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = find_cheapest(*a);
	if (cheapest_node->above_half && cheapest_node->target_node->above_half)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_half)
		&& !(cheapest_node->target_node->above_half))
		rev_rotate_both(a, b, cheapest_node);
	prep_push(a, cheapest_node, 'a');
	prep_push(b, cheapest_node->target_node, 'b');
	pb(a, b);
}

void	move_b_to_a(t_node **a, t_node **b)
{
	prep_push(a, (*b)->target_node, 'a');
	pa(b, a);
}

// den kleinsten Knoten des Stacks nach oben bringen
void	min_on_top(t_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_half)
			rotate_a(a);
		else
			rotate_r_a(a);
	}
}

void	rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rotate_a_b(a, b);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rotate_r_a_b(a, b);
	current_index(*a);
	current_index(*b);
}
