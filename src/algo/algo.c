/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:45:11 by dreule            #+#    #+#             */
/*   Updated: 2025/02/06 15:44:01 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include <stdio.h>

bool	is_sorted(t_list *stack_a)
{
	t_node	*head;

	head = stack_a->head;
	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return (true);
	while (head)
	{
		if (head->next)
		{
			if (head->value > head->next->value)
				return (false);
		}
		head = head->next;
	}
	return (true);
}

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

void	sort_all(t_list *stack_a)
{
	get_index(stack_a);
}

void	sort_vals(t_list *stack_a, t_list *stack_b)
{
	(void)stack_b;
	printf("Pre-Swap\nValue1: %d\nValue2: %d\nValue3: %d\n", stack_a->head->value, stack_a->head->next->value, stack_a->tail->value);
	printf("Pre-Sort\nIndex1: %d\nIndex2: %d\nIndex3: %d\n", stack_a->head->index, stack_a->head->next->index, stack_a->tail->index);
	if (stack_a->size == 2 && !is_sorted(stack_a))
		sa(stack_a);
	// printf("Post-Swap(2)\nValue1: %d\nValue2: %d\n", stack_a->head->value, stack_a->head->next->value);
	if (stack_a->size == 3 && !is_sorted(stack_a))
		sort_three_nodes(stack_a);
	printf("Post-Swap(3)\nValue1: %d\nValue2: %d\nValue2: %d\n\n", stack_a->head->value, stack_a->head->next->value, stack_a->tail->value);
	printf("Post-Sort\nIndex1: %d\nIndex2: %d\nIndex3: %d\n", stack_a->head->index, stack_a->head->next->index, stack_a->tail->index);
	if (stack_a->size > 3 && !is_sorted(stack_a))
		sort_all(stack_a);
}
