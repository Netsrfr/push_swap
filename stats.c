/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:03:52 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/28 14:03:52 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stats(t_stack stack, double t, int ms)
{
	double	ops;
	int		ops2;

	if (t < 1.0)
	{
		ft_printf("push_swap provided %d instructions in %d.%02d milliseconds\n"
				, stack.op_count, ms, (int)(((t * 100) - (int)t * 100) * 100));
		return ;
	}
	ops = (double)stack.op_count / t;
	ops2 = (int)((ops / (int)ops) * 100);
	if (t >= 1.0)
		ft_printf("push_swap provided %d instructions in %d.%02d seconds at a \
rate of %d.%02d operations per second\n", stack.op_count,
				(int)t, ms, (int)ops, ops2);
}

void	ft_read_stats(t_stack stack)
{
	FILE	*stats;
	char	*buffer;
	double	t;
	int		ms;

	stats = fopen("push_swap.time", "r");
	if (stack.op_count == 0)
		return ;
	if (stats == NULL)
	{
		ft_printf("checker executed %d instructions\n", stack.op_count);
		return ;
	}
	buffer = ft_memalloc(sizeof(char) * 9);
	fscanf(stats, "%s", buffer);
	t = (double)ft_atoi(buffer);
	t = t / 1000000.0;
	ms = (int)((t - (int)t) * 100);
	free(buffer);
	ft_print_stats(stack, t, ms);
}
