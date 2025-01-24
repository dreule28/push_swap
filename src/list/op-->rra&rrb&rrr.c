/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op-->rra&rrb&rrr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:41:31 by dreule            #+#    #+#             */
/*   Updated: 2025/01/24 21:04:59 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list *stack_a)
{
	t_node	*first;
	t_node	*last;

	if (stack_a->head == NULL || stack_a->tail == NULL)
		return ;
	first = stack_a->head;
	last = stack_a->tail;
	stack_a->tail = last->prev;
	stack_a->tail->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	stack_a->head = last;
}

void	rrb(t_list *stack_b)
{
	t_node	*first;
	t_node	*last;

	if (stack_b->head == NULL || stack_b->tail == NULL)
		return ;
	first = stack_b->head;
	last = stack_b->tail;
	stack_b->tail = last->prev;
	stack_b->tail->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	stack_b->head = last;
}

void	rrr(t_list *stack_a, t_list *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}