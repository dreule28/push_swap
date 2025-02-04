/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dreule <dreule@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:39:26 by dreule            #+#    #+#             */
/*   Updated: 2025/02/04 17:17:25 by dreule           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

int	*check_dupes(char *args, t_list *stack_a)
{
	char	**nbs;
	int		*ints;
	int		len;

	len = 0;
	nbs = ft_split(args, ' ');
	if (!nbs)
		return ((int *) NULL);
	while (nbs[len])
		len++;
	ints = malloc(sizeof(int) * len);
	if (!ints)
		return ((int *) NULL);
	len = 0;
	while (nbs[len])
	{
		ints[len] = ft_atoi(nbs[len]);
		free(nbs[len]);
		len++;
	}
	free(nbs);
	if (is_dup(ints, len))
		free_ints(args, ints);
	stack_a->size = len;
	return (ints);
}

bool	is_dup(int *ints, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
			if (ints[i] == ints[j++])
				return (true);
		i++;
	}
	return (false);
}

bool	is_valid(char *str)
{
	int		i;
	long	nb;

	i = 0;
	nb = ft_atol(str);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (false);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (false);
		i++;
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

void	pars_args(char **argv, t_list *stack_a)
{
	int			i;
	char		**ints;
	char		*joined_args;
	int			*real_ints;

	i = 0;
	joined_args = build_up_args(argv);
	if (!joined_args || !*joined_args)
		free_joined_args(joined_args);
	ints = ft_split(joined_args, ' ');
	if (!ints)
		free_joined_args(joined_args);
	while (ints[i])
		if (!is_valid(ints[i++]))
			free_all(joined_args, ints);
	free_2d(ints);
	real_ints = check_dupes(joined_args, stack_a);
	if (!real_ints)
		free_joined_args(joined_args);
	fill_stack(stack_a, real_ints);
	free(joined_args);
	free(real_ints);
}
