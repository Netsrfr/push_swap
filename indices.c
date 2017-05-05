/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indices.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 10:41:53 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/18 10:41:53 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_b_insert(t_stack *stack, int i, int j)
{
	if (stack->a[i] > stack->b[0])
	{
		while (stack->a[i] > stack->b[j] && j <= stack->b_size)
		{
			j++;
			if (stack->b[j] == stack->b_max && stack->a[i] < stack->b_max)
			{
				j++;
				while (stack->a[i] < stack->b[j] && j <= stack->b_size)
					j++;
				return (j);
			}
		}
	}
	else if (stack->a[i] < stack->b[0])
	{
		while (stack->a[i] < stack->b[j] && j <= stack->b_size)
		{
			j++;
		}
	}
	return (j);
}

int		ft_b_index(t_stack *stack, int i)
{
	int	j;

	j = 0;
	if (stack->a[i] > stack->b[0] && stack->a[i] < stack->b[stack->b_size - 1])
		return (j);
	if (stack->a[i] > stack->b_max)
	{
		if (stack->b[stack->b_size - 1] == stack->b_min)
			return (0);
		while (stack->b[j] != stack->b_min)
			j++;
		return (j + 1);
	}
	if (stack->a[i] < stack->b_min)
	{
		if (stack->b[0] == stack->b_max)
			return (0);
		while (stack->b[j] != stack->b_min)
			j++;
		return (j + 1);
	}
	j = ft_b_insert(stack, i, j);
	return (j);
}

int		ft_a_insert(t_stack *stack, int i, int j)
{
	if (stack->b[i] > stack->a[0])
	{
		while (stack->b[i] > stack->a[j] && j <= stack->a_size)
		{
			j++;
		}
	}
	else if (stack->b[i] < stack->a[0])
	{
		while (stack->b[i] < stack->a[j] && j <= stack->a_size)
		{
			j++;
			if (stack->a[j] == stack->a_min && stack->b[i] < stack->a_max)
			{
				j++;
				while (stack->b[i] > stack->a[j] && j <= stack->a_size)
					j++;
				return (j);
			}
		}
	}
	return (j);
}

int		ft_a_index(t_stack *stack, int i)
{
	int	j;

	j = 0;
	if (stack->b[i] < stack->a[0] && stack->b[i] > stack->a[stack->a_size - 1])
		return (j);
	if (stack->b[i] > stack->a_max)
	{
		if (stack->a[0] == stack->a_min)
			return (0);
		while (stack->a[j] != stack->a_min)
			j++;
		return (j);
	}
	if (stack->b[i] < stack->a_min)
	{
		if (stack->a[0] == stack->a_max)
			return (1);
		while (stack->a[j] != stack->a_min)
			j++;
		return (j);
	}
	j = ft_a_insert(stack, i, j);
	return (j);
}
