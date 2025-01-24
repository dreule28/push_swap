/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:07:25 by dreule            #+#    #+#             */
/*   Updated: 2025/01/24 20:30:42 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list *stack_a)
{
	t_node	*first;
	t_node	*last;

	if (stack_a->head == NULL || stack_a->tail == NULL)
		return ;
	first = stack_a->head;
	last = stack_a->tail;
	stack_a->head = first->next;
	stack_a->head->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	stack_a->tail = first;
}

void	rb(t_list *stack_b)
{
	t_node	*first;
	t_node	*last;

	if (stack_b->head == NULL || stack_b->tail == NULL)
		return ;
	first = stack_b->head;
	last = stack_b->tail;
	stack_b->head = first->next;
	stack_b->head->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	stack_b->tail = first;
}

void	rr(t_list *stack_a, t_list *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}