/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:45:11 by dreule            #+#    #+#             */
/*   Updated: 2025/02/06 16:52:59 by dreule           ###   ########.fr       */
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

void	sort_vals(t_list *stack_a, t_list *stack_b)
{
	(void)stack_b;
	printf("Pre-Sort\nValue1: %d\nValue2: %d\nValue3: %d\n\n", stack_a->head->value, stack_a->head->next->value, stack_a->tail->value);
	printf("Pre-Sort\nIndex1: %d\nIndex2: %d\nIndex3: %d\n\n", stack_a->head->index, stack_a->head->next->index, stack_a->tail->index);
	printf("Pre-Sort\npos1: %d\npos2: %d\npos3: %d\n", stack_a->head->pos, stack_a->head->next->pos, stack_a->tail->pos);
	if (stack_a->size == 2 && !is_sorted(stack_a))
		sa(stack_a);
	// printf("Post-Swap(2)\nValue1: %d\nValue2: %d\n", stack_a->head->value, stack_a->head->next->value);
	if (stack_a->size == 3 && !is_sorted(stack_a))
		sort_three_nodes(stack_a);
	printf("Post-Swap(3)\nValue1: %d\nValue2: %d\nValue2: %d\n\n", stack_a->head->value, stack_a->head->next->value, stack_a->tail->value);
	printf("Post-Sort\nIndex1: %d\nIndex2: %d\nIndex3: %d\n\n", stack_a->head->index, stack_a->head->next->index, stack_a->tail->index);
	printf("Post-Sort\npos1: %d\npos2: %d\npos3: %d\n\n", stack_a->head->pos, stack_a->head->next->pos, stack_a->tail->pos);
	// if (stack_a->size > 3 && !is_sorted(stack_a))
	// 	sort_all(stack_a);
}
