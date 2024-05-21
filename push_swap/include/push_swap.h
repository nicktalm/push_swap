/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:56:12 by ntalmon           #+#    #+#             */
/*   Updated: 2024/01/23 11:35:52 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include "../lib/printf/ft_printf.h"

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	bool			above_half;
	bool			cheapest;
	int				nbr;
	int				index;
	int				costs_push;
	struct s_node	*target_node;
	struct s_node	*next;
}	t_node;

//operations
void	swap_a(t_node **stack);
void	swap_b(t_node **stack);
void	swap_a_b(t_node **stacka, t_node **stackb);
void	pa(t_node **fromb, t_node **toa);
void	pb(t_node **froma, t_node **tob);

void	rotate_a(t_node **stack);
void	rotate_b(t_node **stack);
void	rotate_a_b(t_node **stacka, t_node **stackb);

void	rotate_r_a(t_node **stack);
void	rotate_r_b(t_node **stack);
void	rotate_r_a_b(t_node **stacka, t_node **stackb);

//list_func

t_node	*ft_lstnew_new(void *content);
void	ft_lstadd_back_new(t_node **lst, t_node *new);
void	ft_lstadd_front_new(t_node **lst, t_node *new);
t_node	*ft_lstlast_new(t_node *lst);

//a_to_b
void	current_index(t_node *stack);
void	set_a_target(t_node *a, t_node *b);
void	cost_analysis_a(t_node *a, t_node *b);
void	set_cheapest_node(t_node *stack);
void	init_nodes_a(t_node *a, t_node *b);

//b_to_a
void	init_nodes_b(t_node *a, t_node *b);
void	set_b_target(t_node *a, t_node *b);

//sort_stack
void	sort_three(t_node **stack);
void	sort_stacks(t_node **a, t_node **b);

//sort_stack_2
void	move_a_to_b(t_node **a, t_node **b);
void	move_b_to_a(t_node **a, t_node **b);
void	min_on_top(t_node **a);
void	rotate_both(t_node **a, t_node **b, t_node *cheapest_node);
void	rev_rotate_both(t_node **a, t_node **b, t_node *cheapest_node);

//helper
void	prep_push(t_node **s, t_node *top, char name);
t_node	*find_cheapest(t_node *stack);
t_node	*find_max(t_node *stack);
t_node	*find_min(t_node *stack);

//helper_2
long	ft_atol(const char *string);
int		count_nbr(int argc, char **argv);
int		list_a_sorted(t_node *stack);
int		stack_size(t_node *stack);

//push_swap
int		list_a_sorted(t_node *stack);

//parsing
char	**parsing2(int argc, char **argv);
t_node	*parsing(t_node	*list_a, int argc, char **argv);

//checks
void	check_nbr(char **string);
void	check_min_max(char **string);
void	check_dup(char **string);
void	check_list(char **string);
void	check_spaces(char **argv);

//error_free
void	error(void);
void	error_2(char **string);
void	free_list(t_node *list_a);
void	free_string(char **string);

#endif