/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:53:12 by dreule            #+#    #+#             */
/*   Updated: 2025/02/04 11:57:18 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	init_stacks(t_list *stack_a, t_list *stack_b)
{
	stack_a->head = NULL;
	stack_a->tail = NULL;
	stack_a->size = 0;
	stack_b->head = NULL;
	stack_b->tail = NULL;
	stack_b->size = 0;
}
