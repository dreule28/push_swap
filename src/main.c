/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:32:02 by dreule            #+#    #+#             */
/*   Updated: 2025/02/05 13:30:21 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	stack_a;
	t_list	stack_b;

	if (argc < 2)
		error("Error\n");
	init_stacks(&stack_a, &stack_b);
	pars_args(argv, &stack_a);
	sort_vals(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
/*
	dorker valgrind --leak-check=full
*/
