/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:52:56 by dreule            #+#    #+#             */
/*   Updated: 2025/02/03 13:35:17 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
void	free_joined_args(char *joined)
{
	free(joined);
	error("Error\n");
}

void	free_2d(char **array)
{
	int	i;

	i = 0;
	while(array[i])
		free(array[i++]);
	free(array);
}

void	free_all(char *joined, char **ints)
{
	free(joined);
	free_2d(ints);
	error("Error\n");
}
