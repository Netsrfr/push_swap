/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handler_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 10:51:19 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/10 10:51:19 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	ft_sa(t_stack stack)
{
	stack = ft_swap_a(stack);
	write(1, "sa\n", 3);
	stack.op_count++;
	return (stack);
}

t_stack	ft_ss(t_stack stack)
{
	stack = ft_swap_ab(stack);
	write(1, "ss\n", 3);
	stack.op_count++;
	return (stack);
}

t_stack	ft_pa(t_stack stack)
{
	stack = ft_push_a(stack);
	write(1, "pa\n", 3);
	stack.op_count++;
	return (stack);
}

t_stack	ft_pb(t_stack stack)
{
	stack = ft_push_b(stack);
	write(1, "pb\n", 3);
	stack.op_count++;
	return (stack);
}
