#ifndef LIST_H
# define LIST_H

//Includes -- BEGIN
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
//Includes -- END
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

#endif