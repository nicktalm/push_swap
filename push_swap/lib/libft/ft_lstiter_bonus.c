/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:53:12 by ntalmon           #+#    #+#             */
/*   Updated: 2023/10/24 17:34:08 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// eine gegebene Funktion f auf jedes Element (Node) anzuwenden
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*c;

	c = lst;
	if (lst == NULL || f == NULL)
		return ;
	while (c != NULL)
	{
		f(c->content);
		c = c->next;
	}
}
