/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op-->sa&sb&ss.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:46:03 by dreule            #+#    #+#             */
/*   Updated: 2025/01/24 20:31:49 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *stack_a)
{
	t_node	*first;
	t_node	*second;

	if (!stack_a || !stack_a->head || !stack_a->head->next)
		return ;
	first = stack_a->head;
	second = stack_a->head->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack_a->head = second;
	write(1, "sa", 1);
}

void	sb(t_list *stack_b)
{
	t_node	*first;
	t_node	*second;

	if (!stack_b || !stack_b->head || !stack_b->head->next)
		return ;
	first = stack_b->head;
	second = stack_b->head->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	stack_b->head = second;
	write(1, "sb", 1);
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a);
	sb(stack_a);
}
