/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:08:31 by ntalmon           #+#    #+#             */
/*   Updated: 2024/01/23 15:45:32 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_nbr(char **string)
{
	int	i;
	int	j;

	j = 0;
	while (string[j])
	{
		i = 0;
		if (string[j][i] == '-')
		{
			i++;
			if ((string[j][i] < '0' || string[j][i] > '9'))
			{
				error_2(string);
			}
		}
		while (string[j][i])
		{
			if ((string[j][i] < '0' || string[j][i] > '9'))
				error_2(string);
			i++;
		}
		j++;
	}
}

void	check_min_max(char **string)
{
	int		i;
	long	num;

	i = 0;
	while (string[i] != NULL)
	{
		num = ft_atol(string[i]);
		if (num > INT_MAX || num < INT_MIN)
			error_2(string);
		i++;
	}
}

void	check_dup(char **string)
{
	int	i;
	int	j;

	i = 0;
	while (string[i + 1])
	{
		j = i + 1;
		while (string[j])
		{
			if (ft_atoi(string[i]) == ft_atoi(string[j]))
				error_2(string);
			j++;
		}
		i++;
	}
}

void	check_list(char **string)
{
	check_nbr(string);
	check_min_max(string);
	check_dup(string);
}

void	check_spaces(char **argv)
{
	int	i;
	int	j;
	int	c;

	j = 1;
	c = 0;
	while (argv[j])
	{
		c = 0;
		i = 0;
		while (argv[j][i] != '\0')
		{
			if (argv[j][i] == ' ' || argv[j][i] == '\t' || argv[j][i] == '\n'
				|| argv[j][i] == '\v' || argv[j][i] == '\f'
				|| argv[j][i] == '\r')
				c++;
			i++;
		}
		if (i == 0 || i == c)
		{
			ft_printf("TEST!\n");
			error ();
		}
		j++;
	}
}
