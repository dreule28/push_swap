/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op-->pa&pb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 20:31:35 by dreule            #+#    #+#             */
/*   Updated: 2025/01/24 20:32:02 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp;

	if (stack_b->head == NULL)
		return ;
	temp = stack_b->head;
	stack_b->head = stack_b->head->next;
	if (stack_b->head)
		stack_a->head->prev = NULL;
	stack_a->head = temp;
	write(1, "pa", 1);
}

void	pb(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp;

	if (stack_a->head == NULL)
		return ;
	temp = stack_a->head->next;
	stack_a->head = stack_a->head->next;
	if (stack_a->head)
		stack_b->head->prev = NULL;
	stack_b->head = temp;
	write(1, "pa", 1);
}
