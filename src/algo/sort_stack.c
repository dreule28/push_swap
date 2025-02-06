/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:52:00 by dreule            #+#    #+#             */
/*   Updated: 2025/02/06 16:52:49 by dreule           ###   ########.fr       */
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

void	sort_all(t_list *stack_a)
{
	get_index(stack_a);
}
