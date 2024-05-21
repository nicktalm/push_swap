/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:06:44 by ntalmon           #+#    #+#             */
/*   Updated: 2024/01/12 16:47:57 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_a(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back_new(stack, tmp);
	ft_printf("ra\n");
}

void	rotate_b(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back_new(stack, tmp);
	ft_printf("rb\n");
}

void	rotate_a_b(t_node **stacka, t_node **stackb)
{
	t_node	*tmp;

	tmp = *stacka;
	*stacka = (*stacka)->next;
	tmp->next = NULL;
	ft_lstadd_back_new(stacka, tmp);
	tmp = *stackb;
	*stackb = (*stackb)->next;
	tmp->next = NULL;
	ft_lstadd_back_new(stackb, tmp);
	ft_printf("rr\n");
}
