/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:13:09 by dreule            #+#    #+#             */
/*   Updated: 2024/10/14 09:34:55 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*arr;
	size_t			store;
	size_t			i;

	store = count * size;
	arr = malloc(store);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < store)
	{
		((unsigned char *)arr)[i] = 0;
		i++;
	}
	return (arr);
}
