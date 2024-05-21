/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:14:07 by ntalmon           #+#    #+#             */
/*   Updated: 2024/01/18 17:41:45 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error(void)
{
	write (2, "Error\n", 6);
	exit (0);
}

void	error_2(char **string)
{
	write (2, "Error\n", 6);
	free_string(string);
	exit (0);
}

void	free_string(char **string)
{
	int	j;

	j = 0;
	while (string[j])
	{
		free(string[j]);
		j++;
	}
	free(string);
}

void	free_list(t_node *list_a)
{
	t_node	*tmp;

	while (list_a)
	{
		tmp = list_a->next;
		free(list_a);
		list_a = tmp;
	}
}
