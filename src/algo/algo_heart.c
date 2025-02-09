/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_heart.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:07:29 by dreule            #+#    #+#             */
/*   Updated: 2025/02/09 02:39:28 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	do_rrr(t_list *stack_a, t_list *stack_b)
{
	t_node	*best_move;

	best_move = stack_b->best_move_node;
	while (best_move->cost && best_move->target_node->cost)
	{
		rrr(stack_a, stack_b);
		best_move->cost--;
		best_move->target_node->cost--;
	}
	if (best_move->cost)
		while (best_move->cost--)
			rrb(stack_b);
	else if (best_move->target_node->cost)
		while (best_move->target_node->cost--)
			rra(stack_a);
}

void	do_rr(t_list *stack_a, t_list *stack_b)
{
	t_node	*best_move;

	best_move = stack_b->best_move_node;
	while (best_move->cost && best_move->target_node->cost)
	{
		rr(stack_a, stack_b);
		best_move->cost--;
		best_move->target_node->cost--;
	}
	if (best_move->cost)
		while (best_move->cost--)
			rb(stack_b);
	else if (best_move->target_node->cost)
		while (best_move->target_node->cost--)
			ra(stack_a);
}

void	rot_or_revrot(t_list *stack_a, t_list *stack_b)
{
	t_node	*best_move;

	best_move = stack_b->best_move_node;
	if (best_move->target_node->pos > stack_a->curr_size / 2)
		while (best_move->target_node->cost--)
			rra(stack_a);
	if (best_move->target_node->pos <= stack_a->curr_size / 2)
		while (best_move->target_node->cost--)
			ra(stack_a);
	if (best_move->pos > stack_b->curr_size / 2)
		while (best_move->cost--)
			rrb(stack_b);
	if (best_move->pos <= stack_b->curr_size / 2)
		while (best_move->cost--)
			rb(stack_b);
}

void	chose_ops(t_list *stack_a, t_list *stack_b)
{
	t_node	*best_move;

	best_move = stack_b->best_move_node;
	if (best_move->pos > stack_b->curr_size / 2
		&& best_move->target_node->pos > stack_a->curr_size / 2)
		do_rrr(stack_a, stack_b);
	else if (best_move->pos <= stack_b->curr_size / 2
		&& best_move->target_node->pos <= stack_a->curr_size / 2)
		do_rr(stack_a, stack_b);
	else
		rot_or_revrot(stack_a, stack_b);
	pa(stack_a, stack_b);
}
