/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_costs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:23:14 by dreule            #+#    #+#             */
/*   Updated: 2025/02/09 01:50:41 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	assign_costs(t_list *stack_a, t_list *stack_b)
{
	t_node	*head_a;
	t_node	*head_b;

	head_a = stack_a->head;
	head_b = stack_b->head;
	while (head_a)
	{
		if (head_a->pos > stack_a->curr_size / 2)
			head_a->cost = stack_a->curr_size - head_a->pos;
		else
			head_a->cost = head_a->pos;
		head_a = head_a->next;
	}
	while (head_b)
	{
		if (head_b->pos > stack_b->curr_size / 2)
			head_b->cost = stack_b->curr_size - head_b->pos;
		else
			head_b->cost = head_b->pos;
		head_b = head_b->next;
	}
}

void	find_cheapest_move(t_list *stack_a, t_list *stack_b)
{
	int		cheapest;
	t_node	*head_b;

	assign_costs(stack_a, stack_b);
	cheapest = stack_b->head->cost + stack_b->head->target_node->cost;
	stack_b->best_move_node = stack_b->head;
	head_b = stack_b->head->next;
	while (head_b)
	{
		if (cheapest > head_b->cost + head_b->target_node->cost)
		{
			cheapest = head_b->cost + head_b->target_node->cost;
			stack_b->best_move_node = head_b;
		}
		head_b = head_b->next;
	}
}
