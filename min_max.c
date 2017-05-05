/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 14:02:46 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/11 14:02:46 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_a_outbound(int value, t_stack *stack, int i)
{
	if (stack->a_size == 1)
	{
		stack->a_min = stack->a[0];
		stack->a_max = stack->a[0];
	}
	else if (stack->a_min == value)
	{
		stack->a_min = stack->a[0];
		while (i < stack->a_size)
		{
			if (stack->a[i] < stack->a_min)
				stack->a_min = stack->a[i];
			i++;
		}
	}
	else if (stack->a_max == value)
	{
		stack->a_max = stack->a[0];
		while (i < stack->a_size)
		{
			if (stack->a[i] > stack->a_max)
				stack->a_max = stack->a[i];
			i++;
		}
	}
}

void	ft_b_outbound(int value, t_stack *stack, int i)
{
	if (stack->b_size == 1)
	{
		stack->b_min = stack->b[0];
		stack->b_max = stack->b[0];
	}
	else if (stack->b_min == value)
	{
		stack->b_min = stack->b[0];
		while (i < stack->b_size)
		{
			if (stack->b[i] < stack->b_min)
				stack->b_min = stack->b[i];
			i++;
		}
	}
	else if (stack->b_max == value)
	{
		stack->b_max = stack->b[0];
		while (i < stack->b_size)
		{
			if (stack->b[i] > stack->b_max)
				stack->b_max = stack->b[i];
			i++;
		}
	}
}

void	ft_b_inbound(int value, t_stack *stack)
{
	if (stack->b_size == 1)
	{
		stack->b_min = value;
		stack->b_max = value;
	}
	else
	{
		if (value < stack->b_min)
			stack->b_min = value;
		if (value > stack->b_max)
			stack->b_max = value;
	}
	ft_a_outbound(value, stack, 1);
}

void	ft_a_inbound(int value, t_stack *stack)
{
	if (stack->a_size == 1)
	{
		stack->a_min = value;
		stack->a_max = value;
	}
	else
	{
		if (value < stack->a_min)
			stack->a_min = value;
		if (value > stack->a_max)
			stack->a_max = value;
	}
	ft_b_outbound(value, stack, 1);
}
