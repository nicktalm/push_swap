/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:26:24 by ntalmon           #+#    #+#             */
/*   Updated: 2024/01/23 11:35:52 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// vorbereiten der Stacks für den push
void	prep_push(t_node **stack, t_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_half)
				rotate_a(stack);
			else
				rotate_r_a(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_half)
				rotate_b(stack);
			else
				rotate_r_b(stack);
		}
	}
}

t_node	*find_cheapest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_node	*find_max(t_node *stack)
{
	int		max;
	t_node	*max_nbr;

	max = INT_MIN;
	max_nbr = NULL;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_nbr = stack;
		}
		stack = stack->next;
	}
	return (max_nbr);
}

t_node	*find_min(t_node *stack)
{
	int		min;
	t_node	*min_nbr;

	if (!stack)
		return (NULL);
	min = INT_MAX;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			min_nbr = stack;
		}
		stack = stack->next;
	}
	return (min_nbr);
}
