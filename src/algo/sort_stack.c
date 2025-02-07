/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:52:00 by dreule            #+#    #+#             */
/*   Updated: 2025/02/07 12:48:57 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

void	sort_three_nodes(t_list *stack_a)
{
	t_node	*biggest_node;

	biggest_node = stack_a->head;
	if (stack_a->head->next->value > biggest_node->value)
		biggest_node = stack_a->head->next;
	if (stack_a->tail->value > biggest_node->value)
		biggest_node = stack_a->tail;
	if (biggest_node == stack_a->head)
	{
		ra(stack_a);
		if (!is_sorted(stack_a))
			sa(stack_a);
	}
	else if (biggest_node == stack_a->head->next)
	{
		rra(stack_a);
		if (!is_sorted(stack_a))
			sa(stack_a);
	}
	else if (!is_sorted(stack_a))
		sa(stack_a);
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

void	sort_all(t_list *stack_a, t_list *stack_b)
{
	get_index(stack_a);
	get_pos(stack_a, stack_b);
}
