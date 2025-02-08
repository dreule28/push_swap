/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:31:35 by dreule            #+#    #+#             */
/*   Updated: 2025/02/08 22:58:49 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list *stack_a, t_list *stack_b)
{
	t_node	*temp;

	if (stack_b == NULL || stack_b->head == NULL)
		return ;
	temp = stack_b->head;
	stack_b->head = stack_b->head->next;
	if (stack_b->head)
		stack_b->head->prev = NULL;
	else
		stack_b->tail = NULL;
	temp->next = stack_a->head;
	if (stack_a->head)
		stack_a->head->prev = temp;
	else
		stack_a->tail = temp;
	stack_a->head = temp;
	stack_a->curr_size++;
	stack_b->curr_size--;
	write(1, "pa\n", 3);
}

void	pb(t_list *stack_a, t_list *stack_b)
{
	t_node	*temp;

	if (stack_a == NULL || stack_a->head == NULL)
		return ;
	temp = stack_a->head;
	stack_a->head = stack_a->head->next;
	if (stack_a->head)
		stack_a->head->prev = NULL;
	else
		stack_a->tail = NULL;
	temp->next = stack_b->head;
	if (stack_b->head)
		stack_b->head->prev = temp;
	else
		stack_b->tail = temp;
	stack_b->head = temp;
	stack_a->curr_size;
	stack_b->curr_size++;
	write(1, "pb\n", 3);
}
