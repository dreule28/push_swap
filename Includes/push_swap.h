/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:37:23 by dreule            #+#    #+#             */
/*   Updated: 2024/12/27 21:00:05 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//Includes -- BEGIN
# include "libft.h"
// # include "parser.h"
// # include "list.h"
// # include "algo.h"
//Includes -- END

//Structs -- BEGIN

/*
	Struct for Nodes --> will be expanded
*/
typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

/*
	Struct that holds pointer to begin & end of list + size
	Metaphor : vassel for a - l on keyboard including them
*/
typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	size_t	size;
}					t_list;

//Structs -- END



//Functions -- BEGIN
	//Parsing -- BEGIN
void	print_msg(void);
	//Parsing -- END
	//List -- BEGIN

void	print_msgALGO(void);
	//List -- END

//Functions -- END

#endif
