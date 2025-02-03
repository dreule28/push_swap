/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:39:26 by dreule            #+#    #+#             */
/*   Updated: 2025/02/03 13:45:29 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"



bool	is_valid(char *ints)
{
	int		i;
	long	nb;

	i = 0;
	nb = ft_atol(ints);
	if (ints[i] == "-" || ints[i] == "+")
		i++;
	if (!ints[i])
		return (false);
	while (ints[i++])
	{
		if (!(ints[i] >= 0 && ints[i] <= 9))
			return (false);
	}
	if (nb > INT_MAX || nb < INT_MIN)
		return (false);
	return (true);
}

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

void	pars_args(char **argv)
{
	int	i;
	int	**ints;
	int	*joined_args;

	i = 0;
	joined_args = build_up_args(argv);
	if (!joined_args)
		free_joined_args(joined_args);
	ints = ft_split(joined_args, ' ');
	if (!ints)
		free_joined_args(joined_args);
	while (ints[i])
	{
		if (!is_valid(ints[i++]))
			free_all(joined_args, ints);
		free_2d(ints);
	}

}