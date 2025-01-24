/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 10:46:03 by dreule            #+#    #+#             */
/*   Updated: 2025/01/24 11:06:53 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *stack_a)
{
	t_node	*curr;

	curr = stack_a->head;
	if (curr->prev == NULL && curr->next != NULL)
	{
		curr = curr->next;
	}
}

void	sb(t_list *stack_b)
{
	t_node	*curr;

	curr = stack_b->head;
	if (curr->prev == NULL && curr->next != NULL)
	{
		curr = curr->next;
	}
}

void	ss(t_list*list)
{
	sb(list);
	sa(list);
}

void	pa(t_list *stack_a, t_list *stack_b)
{
	t_list	temp;

	if (stack_a->head->prev = NULL && stack_b->head->prev == NULL)
	{
		temp.head = stack_b->head;
		stack_b->head = stack_a->head;
		stack_a->head = temp.head;
	}
}

void	pb(t_list *stack_a, t_list *stack_b)
{
	t_list	temp;

	if (stack_b->head->prev = NULL && stack_b->head->prev == NULL)
	{
		temp.head = stack_a->head;
		stack_a->head = stack_b->head;
		stack_a->head = temp.head;
	}
}
