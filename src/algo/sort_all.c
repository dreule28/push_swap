/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:26:53 by dreule            #+#    #+#             */
/*   Updated: 2025/02/07 22:31:37 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	get_pos(t_list *stack_a, t_list *stack_b)
{
	int		pos;
	t_node	*head_a;
	t_node	*head_b;

	pos = 1;
	head_a = stack_a->head;
	head_b = stack_b->head;
	while (head_a)
	{
		head_a->pos = pos++;
		head_a = head_a->next;
	}
	pos = 1;
	while (head_b)
	{
		head_b->pos = pos++;
		head_b = head_b->next;
	}
}

void	split_to_three(t_list *stack_a, t_list *stack_b)
{
	int	pushed;
	int	iter;

	pushed = 0;
	iter = 0;
	if (stack_a->size > 6)
	{
		while (iter < stack_a->size && pushed < stack_a->size / 2)
		{
			if (stack_a->head->index <= stack_a->size / 2)
			{
				pb(stack_a, stack_b);
				pushed++;
			}
			else
			{
				ra(stack_a);
				iter++;
			}
		}
	}
	while (stack_a->size - pushed > 3)
		pb(stack_a, stack_b);
	pushed++;
}

void	get_index(t_list *stack_a)
{
	t_node	*curr;
	t_node	*compare;

	curr = stack_a->head;
	while (curr)
	{
		curr->index = 1;
		compare = stack_a->head;
		while (compare)
		{
			if (compare->value < curr->value)
				curr->index++;
			compare = compare->next;
		}
		curr = curr->next;
	}
}

void	sort_all(t_list *stack_a, t_list *stack_b)
{
	t_node *min_index;

	stack_a->curr_size = stack_a->size;
	stack_b->curr_size = stack_b->size;
	get_index(stack_a);
	split_to_three(stack_a, stack_b);
	sort_three_nodes(stack_a);
	while (stack_b->head)
	{
		get_pos(stack_a, stack_b);
		find_targets(stack_a, stack_b);
	}
}
