/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:26:53 by dreule            #+#    #+#             */
/*   Updated: 2025/02/09 03:10:02 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	get_index(t_list *stack_a)
{
	t_node	*top;
	t_node	*max_node;
	int		size;

	size = stack_a->size;
	while (size--)
	{
		top = stack_a->head;
		max_node = top;
		while (top)
		{
			if (top->next)
			{
				if (max_node->index > 0)
					max_node = top->next;
				if (max_node->value < top->next->value && top->next->index == 0)
					max_node = top->next;
			}
			top = top->next;
		}
		max_node->index = size + 1;
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
				ra(stack_a);
			iter++;
		}
	}
	while (stack_a->size - pushed++ > 3)
		pb(stack_a, stack_b);
}

void	get_pos(t_list *stack_a, t_list *stack_b)
{
	int		pos;
	t_node	*head_a;
	t_node	*head_b;

	pos = 0;
	head_a = stack_a->head;
	head_b = stack_b->head;
	while (head_a)
	{
		head_a->pos = pos++;
		head_a = head_a->next;
	}
	pos = 0;
	while (head_b)
	{
		head_b->pos = pos++;
		head_b = head_b->next;
	}
}

void	find_targets(t_list *stack_a, t_list *stack_b)
{
	int		smallest_bigger;
	t_node	*smallest_index;
	t_node	*head_a;
	t_node	*head_b;

	smallest_index = get_smallest_index(stack_a->head);
	head_b = stack_b->head;
	while (head_b)
	{
		head_a = stack_a->head;
		head_b->target_node = NULL;
		smallest_bigger = INT_MAX;
		while (head_a)
		{
			if (head_a->index > head_b->index && head_a->index < smallest_bigger)
			{
				smallest_bigger = head_a->index;
				head_b->target_node = head_a;
			}
			head_a = head_a->next;
		}
		if (!head_b->target_node)
			head_b->target_node = smallest_index;
		head_b = head_b->next;
	}
}

void	sort_all(t_list *stack_a, t_list *stack_b)
{
	t_node *min_index;

	stack_a->curr_size = stack_a->size;
	stack_b->curr_size = stack_b->size;
	// get_index(stack_a);
	split_to_three(stack_a, stack_b);
	sort_three_nodes(stack_a);
	while (stack_b->head)
	{
		get_pos(stack_a, stack_b);
		find_targets(stack_a, stack_b);
		find_cheapest_move(stack_a, stack_b);
		chose_ops(stack_a, stack_b);
	}
	if (!is_sorted(stack_a))
	{
		min_index = get_smallest_index(stack_a->head);
		get_pos(stack_a, stack_b);
		if (min_index->pos > stack_a->size / 2)
			while (stack_a->size - min_index->pos++ > 0)
				rra(stack_a);
		else
			while (min_index->pos--)
				ra(stack_a);
	}
}
