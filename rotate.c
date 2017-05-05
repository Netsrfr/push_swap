/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 16:57:10 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/06 16:57:10 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	ft_rotate_a(t_stack stack)
{
	int	temp;
	int	i;

	if (stack.a_size < 2)
		return (stack);
	i = 0;
	temp = stack.a[0];
	while (i < stack.a_size - 1)
	{
		stack.a[i] = stack.a[i + 1];
		i++;
	}
	stack.a[i] = temp;
	return (stack);
}

t_stack	ft_rotate_b(t_stack stack)
{
	int	temp;
	int	i;

	if (stack.b_size < 2)
		return (stack);
	i = 0;
	temp = stack.b[0];
	while (i < stack.b_size - 1)
	{
		stack.b[i] = stack.b[i + 1];
		i++;
	}
	stack.b[i] = temp;
	return (stack);
}

t_stack	ft_rotate_ab(t_stack stack)
{
	stack = ft_rotate_a(stack);
	stack = ft_rotate_b(stack);
	return (stack);
}
