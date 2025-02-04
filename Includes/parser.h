/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:05:50 by dreule            #+#    #+#             */
/*   Updated: 2025/02/04 10:24:43 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

//Includes -- BEGIN
# include "libft.h"
# include "list.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
//Includes -- END

//FUNCTIONS -- BEGIN
void	pars_args(char **argv, t_list *stack_a);
char	*build_up_args(char **argv);
bool	is_valid(char *ints);
void	error(char *str);
void	free_joined_args(char *joined);
void	free_2d(char **array);
void	free_all(char *joined, char **ints);
bool	is_dup(int *ints, int len);
void	free_ints(char *str, int *ints);
int		*check_dupes(char *args, t_list *stack_a);
void	free_stack(t_list *stack);
void	fill_stack(t_list *stack_a, int *real_ints);
t_node	*add_node(int *value);
void	add_end(t_list *stack, t_node *new_node);
//FUNCTIONS -- END
#endif