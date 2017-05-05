/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_handler_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 11:03:10 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/10 11:03:10 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	ft_rra(t_stack stack)
{
	stack = ft_rrotate_a(stack);
	write(1, "rra\n", 4);
	stack.op_count++;
	return (stack);
}

t_stack	ft_rrb(t_stack stack)
{
	stack = ft_rrotate_b(stack);
	write(1, "rrb\n", 4);
	stack.op_count++;
	return (stack);
}

t_stack	ft_rrr(t_stack stack)
{
	stack = ft_rrotate_ab(stack);
	write(1, "rrr\n", 4);
	stack.op_count++;
	return (stack);
}
