/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_r_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:41:30 by ntalmon           #+#    #+#             */
/*   Updated: 2024/01/12 16:48:48 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_r_a(t_node **stack)
{
	t_node	*tmplast;
	t_node	*seclast;

	tmplast = ft_lstlast_new(*stack);
	seclast = *stack;
	while (seclast != NULL)
	{
		if (seclast->next->next == NULL)
			seclast->next = NULL;
		seclast = seclast->next;
	}
	ft_lstadd_front_new(stack, tmplast);
	ft_printf("rra\n");
}

void	rotate_r_b(t_node **stack)
{
	t_node	*tmplast;
	t_node	*seclast;

	tmplast = ft_lstlast_new(*stack);
	seclast = *stack;
	while (seclast != NULL)
	{
		if (seclast->next->next == NULL)
			seclast->next = NULL;
		seclast = seclast->next;
	}
	ft_lstadd_front_new(stack, tmplast);
	ft_printf("rrb\n");
}

void	rotate_r_a_b(t_node **stacka, t_node **stackb)
{
	t_node	*tmplast;
	t_node	*seclast;

	tmplast = ft_lstlast_new(*stacka);
	seclast = *stacka;
	while (seclast != NULL)
	{
		if (seclast->next->next == NULL)
			seclast->next = NULL;
		seclast = seclast->next;
	}
	ft_lstadd_front_new(stacka, tmplast);
	tmplast = ft_lstlast_new(*stackb);
	seclast = *stackb;
	while (seclast != NULL)
	{
		if (seclast->next->next == NULL)
			seclast->next = NULL;
		seclast = seclast->next;
	}
	ft_lstadd_front_new(stackb, tmplast);
	ft_printf("rrr\n");
}
