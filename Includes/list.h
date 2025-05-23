/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:04:47 by dreule            #+#    #+#             */
/*   Updated: 2025/02/08 20:48:44 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

//Includes -- Begin
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
//Includes -- End

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	int				cost;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target_node;
}					t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	t_node	*best_move_node;
	int		size;
	int		curr_size;
}					t_list;

//FUNCTIONS -- BEGIN
void	swap(t_list *stack);
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *stack_b);
void	pa(t_list *stack_a, t_list *stack_b);
void	pb(t_list *stack_a, t_list *stack_b);
void	rotate(t_list *stack);
void	ra(t_list *stack_a);
void	rb(t_list *stack_b);
void	rr(t_list *stack_a, t_list *stack_b);
void	rev_rotate(t_list *stack);
void	rra(t_list *stack_a);
void	rrb(t_list *stack_b);
void	rrr(t_list *stack_a, t_list *stack_b);
//FUNCTIONS -- END

#endif
