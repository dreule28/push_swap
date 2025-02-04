/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:25:24 by dreule            #+#    #+#             */
/*   Updated: 2025/02/04 16:22:26 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

t_node	*add_node(int *value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ((t_node *)(NULL));
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->value = (*value);
	printf("Value of node : %d\n", new_node->value);
	printf("Adresse: %p\n\n", new_node);
	return (new_node);
}

void	add_end(t_list *stack, t_node *new_node)
{
	if (!stack->head)
	{
		stack->head = new_node;
		stack->tail = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
		return ;
	}
	new_node->prev = stack->tail;
	new_node->next = NULL;
	stack->tail->next = new_node;
	stack->tail = new_node;
}

void	fill_stack(t_list *stack_a, int *real_ints)
{
	t_node		*new_node;
	size_t		i;

	i = 0;
	while (i < stack_a->size)
	{
		new_node = add_node(&real_ints[i]);
		if (!new_node)
			free_stack(stack_a);
		add_end(stack_a, new_node);
		i++;
	}
	free_stack(stack_a);
}
