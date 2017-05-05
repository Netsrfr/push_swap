/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:02:01 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/28 14:02:01 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_single_arg(int *argc, char **argv)
{
	int	i;

	i = 1;
	if (*argc >= 2 && (ft_strcmp(argv[1], "-sv") == 0 \
	|| ft_strcmp(argv[1], "-vs") == 0))
	{
		while (i < *argc - 1)
		{
			argv[i] = ft_strdup(argv[i + 1]);
			i++;
		}
		*argc = *argc - 1;
		return (1);
	}
	return (0);
}

int		ft_dual_arg(int *argc, char **argv, int i)
{
	if (*argc >= 3 && (ft_strcmp(argv[1], "-v") == 0))
		if (ft_strcmp(argv[2], "-s") == 0)
		{
			while (i < *argc - 2)
			{
				argv[i] = ft_strdup(argv[i + 2]);
				i++;
			}
			*argc = *argc - 2;
			return (1);
		}
	if (*argc >= 3 && (ft_strcmp(argv[1], "-s") == 0))
		if (ft_strcmp(argv[2], "-v") == 0)
		{
			while (i < *argc - 2)
			{
				argv[i] = ft_strdup(argv[i + 2]);
				i++;
			}
			*argc = *argc - 2;
			return (1);
		}
	return (0);
}

int		ft_dual_flag(int *argc, char **argv)
{
	if (ft_single_arg(argc, argv) == 1)
		return (2);
	if (ft_dual_arg(argc, argv, 1) == 1)
		return (3);
	return (0);
}

int		ft_single_flag(int *argc, char **argv)
{
	int	i;

	i = 1;
	if (*argc >= 2 && ft_strcmp(argv[1], "-v") == 0)
	{
		while (i < *argc - 1)
		{
			argv[i] = ft_strdup(argv[i + 1]);
			i++;
		}
		*argc = *argc - 1;
		return (1);
	}
	if (*argc >= 2 && ft_strcmp(argv[1], "-s") == 0)
	{
		while (i < *argc - 1)
		{
			argv[i] = ft_strdup(argv[i + 1]);
			i++;
		}
		*argc = *argc - 1;
		return (2);
	}
	return (0);
}

int		ft_options(int *argc, char **argv, t_stack *stack)
{
	int ret;

	stack->debug = 0;
	stack->stats = 0;
	if (ft_dual_flag(argc, argv) != 0)
	{
		stack->debug = 1;
		stack->stats = 1;
		return (2);
	}
	ret = ft_single_flag(argc, argv);
	if (ret == 2)
	{
		stack->stats = 1;
		return (1);
	}
	if (ret == 1)
	{
		stack->debug = 1;
		return (1);
	}
	return (0);
}
