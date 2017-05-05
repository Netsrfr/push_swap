/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 11:02:05 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/18 11:02:05 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ft_calc_shortest(t_sort *sort)
{
	int	i;
	int	temp;
	int temp2;

	i = 0;
	while (sort->a_rrot > i && sort->b_rrot > i)
		i++;
	sort->small = (sort->a_rrot - i) + (sort->b_rrot - i) + i;
	i = 0;
	while (sort->a_rot > i && sort->b_rot > i)
		i++;
	temp = (sort->a_rot - i) + (sort->b_rot - i) + i;
	sort->small = (temp < sort->small) ? temp : sort->small;
	sort->a_dir = (temp > sort->small) ? 1 : 0;
	sort->b_dir = (temp > sort->small) ? 1 : 0;
	temp = (sort->a_rot > sort->a_rrot) ? sort->a_rrot : sort->a_rot;
	temp2 = (sort->b_rot > sort->b_rrot) ? sort->b_rrot : sort->b_rot;
	sort->small = ((temp + temp2) < sort->small) ? temp + temp2 : sort->small;
	if (sort->small == temp + temp2)
	{
		sort->a_dir = (sort->a_rot < sort->a_rrot) ? 0 : 1;
		sort->b_dir = (sort->b_rot < sort->b_rrot) ? 0 : 1;
	}
}

t_sort		ft_fill_sort_a(t_stack *stack, t_sort sort, int i)
{
	sort.a_rot = i;
	sort.a_index = i;
	sort.a_rrot = stack->a_size - i;
	sort.b_index = ft_b_index(stack, i);
	sort.b_rot = sort.b_index;
	sort.b_rrot = stack->b_size - sort.b_index;
	ft_calc_shortest(&sort);
	return (sort);
}

t_sort		ft_fill_sort_b(t_stack *stack, t_sort sort, int i)
{
	sort.b_rot = i;
	sort.b_index = i;
	sort.b_rrot = stack->b_size - i;
	sort.a_index = ft_a_index(stack, i);
	sort.a_rot = sort.a_index;
	sort.a_rrot = stack->a_size - sort.a_index;
	ft_calc_shortest(&sort);
	return (sort);
}

int			ft_in_order(t_stack *stk)
{
	int	i;

	if (stk->a[0] == stk->a_max)
	{
		i = 1;
		while (i < stk->a_size - 1)
		{
			if (stk->a[i] > stk->a[i + 1])
				return (0);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < stk->a_size - 1)
		{
			if (stk->a[i] > stk->a[i + 1] && stk->a[i + 1] != stk->a_max)
				return (0);
			i++;
		}
	}
	return (1);
}

int			ft_is_solved(t_stack stack)
{
	int	i;

	i = 0;
	if (stack.b_size == 0)
	{
		while (i < stack.a_size - 1 && stack.a[i] < stack.a[i + 1])
			i++;
		if (i == stack.a_size - 1)
			return (1);
	}
	return (0);
}
