/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:13:36 by ntalmon           #+#    #+#             */
/*   Updated: 2024/01/18 14:36:46 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*ft_lstnew_new(void *content)
{
	t_node	*t;

	t = (t_node *)malloc(sizeof(t_node));
	if (t == NULL)
		return (NULL);
	t->nbr = *(int *)content;
	t->next = NULL;
	return (t);
}

void	ft_lstadd_back_new(t_node **lst, t_node *new)
{
	t_node	*t;

	t = NULL;
	if (*lst == NULL)
		*lst = new;
	else
	{
		t = ft_lstlast_new(*lst);
		t->next = new;
	}
}

void	ft_lstadd_front_new(t_node **lst, t_node *new)
{
	if (lst == NULL && new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

t_node	*ft_lstlast_new(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
