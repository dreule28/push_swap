/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:57:39 by dreule            #+#    #+#             */
/*   Updated: 2025/02/04 10:24:34 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_joined_args(char *joined)
{
	free(joined);
	error("Error\n");
}

void	free_2d(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	free_all(char *joined, char **ints)
{
	free(joined);
	free_2d(ints);
	error("Error\n");
}

void	free_ints(char *str, int *ints)
{
	free(str);
	free(ints);
	error("Error\n");
}

void	free_stack(t_list *stack)
{
	t_node	*curr;

	curr = stack->head;
	while(curr->next)
	{
		curr = curr->next;
		free(curr->prev);
	}
	free(curr);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	error("Error\n");
}
