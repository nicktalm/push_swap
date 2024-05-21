/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:04:04 by ntalmon           #+#    #+#             */
/*   Updated: 2024/01/18 17:56:07 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	**parsing3(char **split_result, char **string, int *j)
{
	int	x;

	x = 0;
	while (split_result[x] != NULL)
	{
		string[*j] = ft_strdup(split_result[x]);
		(*j)++;
		x++;
	}
	return (split_result);
}

char	**parsing2(int argc, char **argv)
{
	int		i;
	int		j;
	char	**string;
	char	**split_result;
	int		nbr;

	i = 1;
	j = 0;
	nbr = count_nbr(argc, argv);
	string = malloc((nbr + 1) * sizeof(char *));
	string[nbr] = NULL;
	while (i < argc)
	{
		split_result = ft_split(argv[i], ' ');
		parsing3(split_result, string, &j);
		i++;
		free_string(split_result);
	}
	check_list (string);
	return (string);
}

t_node	*parsing(t_node *list_a, int argc, char **argv)
{
	int		*number;
	char	**string;
	int		j;
	t_node	*new_node;

	j = 0;
	check_spaces(argv);
	string = parsing2(argc, argv);
	while (string[j] != NULL)
	{
		number = (int *)malloc(sizeof(int));
		*number = ft_atoi(string[j]);
		new_node = ft_lstnew_new(number);
		free(number);
		if (new_node)
			ft_lstadd_back_new(&list_a, new_node);
		else
			break ;
		j++;
	}
	free_string(string);
	return (list_a);
}
