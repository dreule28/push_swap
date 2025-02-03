/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:39:26 by dreule            #+#    #+#             */
/*   Updated: 2025/02/03 11:17:52 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*build_up_args(char **argv)
{
	char	*joined;
	int		i;
	int		len;

	i = 1;
	len = 0;
	while (argv[i])
		len += ft_strlen(argv[i++]) + 1;
	joined = malloc(len + 1);
	if (!joined)
		return (NULL);
	joined[0] = '\0';
	i = 1;
	while (argv[i])
	{
		ft_strlcat(joined, argv[i], len);
		ft_strlcat(joined, " ", len);
		i++;
	}
	return (joined);
}
