/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:45:11 by dreule            #+#    #+#             */
/*   Updated: 2025/02/08 20:23:35 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include <stdio.h>

void	post_sort(t_list *stack_a);
void	pre_sort(t_list *stack_a);

t_node	*get_smallest_index(t_list *stack_a)
{
	int		smallest_index;
	t_node	*head;
	t_node	*smallest_index_node;

	smallest_index = stack_a->head->index;
	smallest_index_node = stack_a->head;
	head = stack_a->head->next;
	while (head)
	{
		if (smallest_index > head->index)
		{
			smallest_index = head->index;
			smallest_index_node = head;
		}
		head = head->next;
	}
	return (smallest_index_node);
}

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

void	sort_vals(t_list *stack_a, t_list *stack_b)
{
	(void)stack_b;
	pre_sort(stack_a);
	if (stack_a->size == 2 && !is_sorted(stack_a))
		sa(stack_a);
	if (stack_a->size == 3 && !is_sorted(stack_a))
		sort_three_nodes(stack_a);
	post_sort(stack_a);
	if (stack_a->size > 3 && !is_sorted(stack_a))
		sort_all(stack_a, stack_b);
}































void	post_sort(t_list *stack_a)
{
	t_node *current = stack_a->head;
	int i = 1;

	printf("Post-Sort\n\n");
	while (current)
	{
		printf("Index%d: %d\n", i, current->index);
		printf("Value%d: %d\n\n", i, current->value);
		// printf("Pos  %d: %d\n\n", i, current->pos);
		current = current->next;
		i++;
	}
	printf("\n");
}

void	pre_sort(t_list *stack_a)
{
	t_node *current = stack_a->head;
	int i = 1;

	printf("Pre-Sort\n\n");
	while (current)
	{
		printf("Index%d: %d\n", i, current->index);
		printf("Value%d: %d\n\n", i, current->value);
		// printf("Pos  %d: %d\n\n", i, current->pos);
		current = current->next;
		i++;
	}
	printf("\n");
}