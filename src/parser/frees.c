/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:57:39 by dreule            #+#    #+#             */
/*   Updated: 2025/02/04 14:11:37 by dreule           ###   ########.fr       */
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

void	free_all(char *str, char **array)
{
	free(str);
	free_2d(array);
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
	t_node	*next;

	curr = stack->head;
	while (curr)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	stack->head = NULL;
	stack->tail = NULL;
}
