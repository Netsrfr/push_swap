/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:05:33 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/18 11:05:33 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_forwards(t_stack *stack, t_sort *sort)
{
	while (sort->a_rot > 0 && sort->b_rot > 0)
	{
		*stack = ft_rr(*stack);
		sort->a_rot--;
		sort->b_rot--;
	}
	while (sort->a_rot > 0)
	{
		*stack = ft_ra(*stack);
		sort->a_rot--;
	}
	while (sort->b_rot > 0)
	{
		*stack = ft_rb(*stack);
		sort->b_rot--;
	}
}

void	ft_reverse(t_stack *stack, t_sort *sort)
{
	while (sort->a_rrot > 0 && sort->b_rrot > 0)
	{
		*stack = ft_rrr(*stack);
		sort->a_rrot--;
		sort->b_rrot--;
	}
	while (sort->a_rrot > 0)
	{
		*stack = ft_rra(*stack);
		sort->a_rrot--;
	}
	while (sort->b_rrot > 0)
	{
		*stack = ft_rrb(*stack);
		sort->b_rrot--;
	}
}

void	ft_opposite(t_stack *stack, t_sort *sort)
{
	if (sort->a_dir == 0)
		while (sort->a_rot > 0)
		{
			*stack = ft_ra(*stack);
			sort->a_rot--;
		}
	else if (sort->a_dir == 1)
		while (sort->a_rrot > 0)
		{
			*stack = ft_rra(*stack);
			sort->a_rrot--;
		}
	if (sort->b_dir == 0)
		while (sort->b_rot > 0)
		{
			*stack = ft_rb(*stack);
			sort->b_rot--;
		}
	else if (sort->b_dir == 1)
		while (sort->b_rrot > 0)
		{
			*stack = ft_rrb(*stack);
			sort->b_rrot--;
		}
}

void	ft_finish(t_stack *stack)
{
	int i;

	i = 0;
	if (stack->a[0] != stack->a_min)
	{
		while (stack->a[i] != stack->a_min)
			i++;
		if (i >= stack->a_size / 2)
		{
			while (stack->a[0] != stack->a_min)
				*stack = ft_rra(*stack);
		}
		else
		{
			while (stack->a[0] != stack->a_min)
				*stack = ft_ra(*stack);
		}
	}
}

t_stack	ft_start_pa_pa_ss(t_stack stack)
{
	stack = ft_pb(stack);
	stack = ft_pb(stack);
	stack = ft_ss(stack);
	return (stack);
}
