/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:41:31 by dreule            #+#    #+#             */
/*   Updated: 2025/01/31 18:28:45 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_list *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack->head == NULL || stack->tail == NULL)
		return ;
	first = stack->head;
	last = stack->tail;
	stack->tail = last->prev;
	stack->tail->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	stack->head = last;
}

void	rra(t_list *stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_list *stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list *stack_a, t_list *stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
