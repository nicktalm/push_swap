/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:34:27 by ntalmon           #+#    #+#             */
/*   Updated: 2024/01/23 11:34:46 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// suchtfür jeden Knoten in b_list den am besten  Knoten in a_list
// weist diesen als Zielknoten (target_node)
// Wenn kein passender Knoten in a_list gefunden wird,
// Knoten mit dem minimalen Wert in a_list als Zielknoten zugewiesen
void	set_b_target(t_node *a_list, t_node *b_list)
{
	t_node	*current_a;
	t_node	*target_node;
	int		best_match_index;

	while (b_list)
	{
		best_match_index = INT_MAX;
		current_a = a_list;
		while (current_a)
		{
			if (current_a->nbr > b_list->nbr
				&& current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == INT_MAX)
			b_list->target_node = find_min(a_list);
		else
			b_list->target_node = target_node;
		b_list = b_list->next;
	}
}

void	init_nodes_b(t_node *a, t_node *b)
{
	current_index(a);
	current_index(b);
	set_b_target(a, b);
}
