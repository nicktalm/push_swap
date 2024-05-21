/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:51:29 by ntalmon           #+#    #+#             */
/*   Updated: 2024/01/12 16:48:30 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a(t_node **stack)
{
	int	tmp;

	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
	ft_printf("sa\n");
}

void	swap_b(t_node **stack)
{
	int	tmp;

	tmp = (*stack)->nbr;
	(*stack)->nbr = (*stack)->next->nbr;
	(*stack)->next->nbr = tmp;
	ft_printf("sb\n");
}

void	swap_a_b(t_node **stacka, t_node **stackb)
{
	int	tmp;

	tmp = (*stacka)->nbr;
	(*stacka)->nbr = (*stacka)->next->nbr;
	(*stacka)->next->nbr = tmp;
	tmp = (*stackb)->nbr;
	(*stackb)->nbr = (*stackb)->next->nbr;
	(*stackb)->next->nbr = tmp;
	ft_printf("ss\n");
}

void	pa(t_node **fromb, t_node **toa)
{
	t_node	*tmp;

	tmp = *fromb;
	*fromb = (*fromb)->next;
	tmp->next = NULL;
	ft_lstadd_front_new(toa, tmp);
	ft_printf("pa\n");
}

void	pb(t_node **froma, t_node **tob)
{
	t_node	*tmp;

	tmp = *froma;
	*froma = (*froma)->next;
	tmp->next = NULL;
	ft_lstadd_front_new(tob, tmp);
	ft_printf("pb\n");
}
