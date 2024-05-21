/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:52:21 by ntalmon           #+#    #+#             */
/*   Updated: 2024/01/18 17:41:52 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*list_a;
	t_node	*list_b;

	list_a = NULL;
	list_b = NULL;
	if (argc <= 1)
		return (0);
	list_a = parsing(list_a, argc, argv);
	if (!list_a_sorted(list_a))
	{
		if (stack_size(list_a) == 2)
			swap_a(&list_a);
		else if (stack_size(list_a) == 3)
			sort_three(&list_a);
		else
			sort_stacks(&list_a, &list_b);
	}
	free_list(list_a);
	return (0);
}
