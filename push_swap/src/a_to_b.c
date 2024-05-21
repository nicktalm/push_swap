/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:01:00 by ntalmon           #+#    #+#             */
/*   Updated: 2024/01/23 11:35:11 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// weist jedem Knoten einen Index zu
// gibt an ob er sich in der oberen oder unteren Hälfte befindet
void	current_index(t_node *stack)
{
	int	i;
	int	half;

	i = 0;
	if (!stack)
		return ;
	half = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= half)
			stack->above_half = true;
		else
			stack->above_half = false;
		stack = stack->next;
		++i;
	}
}

// sucht jeden Knoten in a_list den am besten passenden Knoten in b_list
// weist diesen als Zielknoten dem entsprechenden Knoten in a_list zu
void	set_a_target(t_node *a_list, t_node *b_list)
{
	t_node	*current_b;
	t_node	*target_node;
	int		best_match_index;

	while (a_list)
	{
		best_match_index = INT_MIN;
		current_b = b_list;
		while (current_b)
		{
			if (current_b->nbr < a_list->nbr
				&& current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == INT_MIN)
			a_list->target_node = find_max(b_list);
		else
			a_list->target_node = target_node;
		a_list = a_list->next;
	}
}

// berechnet die Kosten für das push jedes Knotens in a_list
// basierend auf verschiedenen Faktoren (Index, above_half-Status, target_node)
void	cost_analysis_a(t_node *a_list, t_node *b_list)
{
	int	len_a;
	int	len_b;

	len_a = stack_size(a_list);
	len_b = stack_size(b_list);
	while (a_list)
	{
		a_list->costs_push = a_list->index;
		if (!(a_list->above_half))
			a_list->costs_push = len_a - (a_list->index);
		if (a_list->target_node->above_half)
			a_list->costs_push += a_list->target_node->index;
		else
			a_list->costs_push += len_b - (a_list->target_node->index);
		a_list = a_list->next;
	}
}

// sucht der Knoten mit den wenigsten Kosten und markiert ihn
void	set_cheapest_node(t_node *stack)
{
	int		cheapest_value;
	t_node	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = INT_MAX;
	while (stack)
	{
		if (stack->costs_push < cheapest_value)
		{
			cheapest_value = stack->costs_push;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes_a(t_node *a_list, t_node *b_list)
{
	current_index(a_list);
	current_index(b_list);
	set_a_target(a_list, b_list);
	cost_analysis_a(a_list, b_list);
	set_cheapest_node(a_list);
}
