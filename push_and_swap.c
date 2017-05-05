/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_and_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 20:31:34 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/05 20:31:34 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	ft_swap_a(t_stack stack)
{
	int	temp;

	if (stack.a_size < 2)
		return (stack);
	temp = stack.a[0];
	stack.a[0] = stack.a[1];
	stack.a[1] = temp;
	return (stack);
}

t_stack	ft_swap_b(t_stack stack)
{
	int temp;

	if (stack.a_size < 2)
		return (stack);
	temp = stack.b[0];
	stack.b[0] = stack.b[1];
	stack.b[1] = temp;
	return (stack);
}

t_stack	ft_swap_ab(t_stack stack)
{
	stack = ft_swap_a(stack);
	stack = ft_swap_b(stack);
	return (stack);
}

t_stack	ft_push_b(t_stack stack)
{
	int	temp;
	int	value;

	if (stack.a_size == 0)
		return (stack);
	temp = stack.b_size;
	value = stack.a[0];
	while (temp > 0)
	{
		stack.b[temp] = stack.b[temp - 1];
		temp--;
	}
	stack.b[0] = stack.a[0];
	stack.b_size++;
	while (temp <= stack.a_size - 1)
	{
		stack.a[temp] = stack.a[temp + 1];
		temp++;
	}
	stack.a_size--;
	ft_b_inbound(value, &stack);
	return (stack);
}

t_stack	ft_push_a(t_stack stack)
{
	int	temp;
	int	value;

	if (stack.b_size == 0)
		return (stack);
	temp = stack.a_size;
	value = stack.b[0];
	while (temp > 0)
	{
		stack.a[temp] = stack.a[temp - 1];
		temp--;
	}
	stack.a[0] = stack.b[0];
	stack.a_size++;
	while (temp <= stack.b_size - 1)
	{
		stack.b[temp] = stack.b[temp + 1];
		temp++;
	}
	stack.b_size--;
	ft_a_inbound(value, &stack);
	return (stack);
}
