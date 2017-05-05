/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handler_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 11:01:45 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/10 11:01:45 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	ft_ra(t_stack stack)
{
	stack = ft_rotate_a(stack);
	write(1, "ra\n", 3);
	stack.op_count++;
	return (stack);
}

t_stack	ft_rb(t_stack stack)
{
	stack = ft_rotate_b(stack);
	write(1, "rb\n", 3);
	stack.op_count++;
	return (stack);
}

t_stack	ft_rr(t_stack stack)
{
	stack = ft_rotate_ab(stack);
	write(1, "rr\n", 3);
	stack.op_count++;
	return (stack);
}
