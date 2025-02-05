/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:05:29 by dreule            #+#    #+#             */
/*   Updated: 2025/02/05 18:29:15 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

//Includes -- BEGIN
# include "libft.h"
# include "list.h"
# include "parser.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
//Includes -- END

//FUNCTIONS -- BEGIN
void	sort_vals(t_list *stack_a, t_list *stack_b);
bool	is_sorted(t_list *stack_a);
void	sort_three_nodes(t_list *stack_a);
//FUNCTIONS -- END

#endif