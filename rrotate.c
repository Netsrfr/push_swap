/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:08:24 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/06 17:08:24 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	ft_rrotate_a(t_stack stack)
{
	int	temp;
	int	i;

	i = stack.a_size;
	temp = stack.a[stack.a_size - 1];
	while (i > 0)
	{
		stack.a[i] = stack.a[i - 1];
		i--;
	}
	stack.a[0] = temp;
	return (stack);
}

t_stack	ft_rrotate_b(t_stack stack)
{
	int	temp;
	int	i;

	i = stack.b_size;
	temp = stack.b[stack.b_size - 1];
	while (i > 0)
	{
		stack.b[i] = stack.b[i - 1];
		i--;
	}
	stack.b[0] = temp;
	return (stack);
}

t_stack	ft_rrotate_ab(t_stack stack)
{
	stack = ft_rrotate_a(stack);
	stack = ft_rrotate_b(stack);
	return (stack);
}
