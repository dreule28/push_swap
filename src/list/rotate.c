/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:07:25 by dreule            #+#    #+#             */
/*   Updated: 2025/01/31 15:56:03 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack->head == NULL || stack->head->next == NULL)
		return ;
	first = stack->head;
	last = stack->tail;
	stack->head = first->next;
	stack->head->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	stack->tail = first;
}

void	ra(t_list *stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}
void	rb(t_list *stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_list *stack_a, t_list *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}