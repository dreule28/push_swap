/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:05:29 by dreule            #+#    #+#             */
/*   Updated: 2025/02/09 01:44:57 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

//Includes -- BEGIN
# include "libft.h"
# include "list.h"
# include "parser.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
//Includes -- END

//FUNCTIONS -- BEGIN
void	sort_vals(t_list *stack_a, t_list *stack_b);
bool	is_sorted(t_list *stack_a);
void	sort_three_nodes(t_list *stack_a);
void	sort_all(t_list *stack_a, t_list *stack_b);
void	get_index(t_list *stack_a);
void	get_pos(t_list *stack_a, t_list *stack_b);
void	split_to_three(t_list *stack_a, t_list *stack_b);
void	find_targets(t_list *stack_a, t_list *stack_b);
t_node	*get_smallest_index(t_node *head_a);
void	assign_costs(t_list *stack_a, t_list *stack_b);
void	find_cheapest_move(t_list *stack_a, t_list *stack_b);
void	chose_ops(t_list *stack_a, t_list *stack_b);
void	do_rrr(t_list *stack_a, t_list *stack_b);
void	do_rr(t_list *stack_a, t_list *stack_b);
void	rot_or_revrot(t_list *stack_a, t_list *stack_b);
//FUNCTIONS -- END

#endif