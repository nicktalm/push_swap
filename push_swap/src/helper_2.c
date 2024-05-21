/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:11:28 by ntalmon           #+#    #+#             */
/*   Updated: 2024/01/18 16:32:24 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	ft_atol(const char *string)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (string[i] == '\t' || string[i] == '\n' || string[i] == '\v' || \
			string[i] == '\f' || string[i] == '\r' || string[i] == ' ')
		i++;
	if (string[i] == '-' || string[i] == '+')
	{
		if (string[i] == '-')
			sign = -1;
		i++;
	}
	while (string[i] >= '0' && string[i] <= '9')
	{
		result = result * 10 + (string[i] - '0');
		i++;
	}
	return (result * sign);
}

int	count_nbr(int argc, char **argv)
{
	int		count;
	int		i;
	char	**split_result;
	int		j;

	count = 0;
	i = 1;
	while (i < argc)
	{
		split_result = ft_split(argv[i], ' ');
		if (split_result != NULL)
		{
			j = 0;
			while (split_result[j] != NULL)
			{
				count++;
				j++;
			}
			free_string(split_result);
		}
		i++;
	}
	return (count);
}

int	list_a_sorted(t_node *stack)
{
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_size(t_node *stack)
{
	int	c;

	c = 0;
	while (stack)
	{
		stack = stack->next;
		c++;
	}
	return (c);
}
