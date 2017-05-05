/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 10:56:58 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/18 10:56:58 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_solve_a(t_stack *stack, t_sort *sort, t_sort *temp, int i)
{
	while (stack->b_size != 0)
	{
		i = 1;
		*sort = ft_fill_sort_b(stack, *sort, 0);
		while (i < stack->b_size)
		{
			*temp = ft_fill_sort_b(stack, *sort, i);
			if (temp->small < sort->small)
				sort = temp;
			i++;
		}
		if (sort->a_dir == 1 && sort->b_dir == 1)
			ft_reverse(stack, sort);
		else if (sort->a_dir == 0 && sort->b_dir == 0)
			ft_forwards(stack, sort);
		else
			ft_opposite(stack, sort);
		*stack = ft_pa(*stack);
	}
}

void	ft_solve_b(t_stack *stack)
{
	int		i;
	t_sort	sort;
	t_sort	temp;

	while (ft_in_order(stack) != 1)
	{
		i = 1;
		sort = ft_fill_sort_a(stack, sort, 0);
		while (i < stack->a_size)
		{
			temp = ft_fill_sort_a(stack, sort, i);
			if (temp.small < sort.small)
				sort = temp;
			i++;
		}
		if (sort.a_dir == 1 && sort.b_dir == 1)
			ft_reverse(stack, &sort);
		else if (sort.a_dir == 0 && sort.b_dir == 0)
			ft_forwards(stack, &sort);
		else
			ft_opposite(stack, &sort);
		if (ft_in_order(stack) != 1)
			*stack = ft_pb(*stack);
	}
	ft_solve_a(stack, &sort, &temp, i);
}

void	ft_solve_three(t_stack *stack)
{
	if (stack->a[0] < stack->a[1] && stack->a[1] > stack->a[2])
	{
		if (stack->a[2] < stack->a[0])
			ft_rra(*stack);
		else
		{
			ft_rra(*stack);
			ft_sa(*stack);
		}
	}
	else if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2])
	{
		if (stack->a[0] < stack->a[2])
			ft_sa(*stack);
		else
			ft_ra(*stack);
	}
	else if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
	{
		ft_sa(*stack);
		ft_rra(*stack);
	}
}

void	ft_four_five(t_stack *stack)
{
	t_sort	sort;
	t_sort	temp;

	if (stack->a_size == 5)
		*stack = ft_pb(*stack);
	*stack = ft_pb(*stack);
	if (stack->b[0] < stack->b[1] && stack->a[0] > stack->a[1])
		*stack = ft_ss(*stack);
	else if (stack->b[0] < stack->b[1])
		*stack = ft_rb(*stack);
	ft_solve_three(stack);
	ft_solve_a(stack, &sort, &temp, 0);
	ft_finish(stack);
	exit(0);
}

int		ft_solve_small(t_stack stack)
{
	if (stack.a_size > 5)
		return (0);
	if (stack.a_size == 2)
	{
		if (stack.a[0] > stack.a[1])
			ft_sa(stack);
	}
	else if (stack.a_size == 3)
		ft_solve_three(&stack);
	else if (ft_is_solved(stack) != 1)
		ft_four_five(&stack);
	return (1);
}
