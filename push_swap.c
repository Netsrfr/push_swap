/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 09:55:46 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/07 09:55:46 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stats(clock_t begin, clock_t end)
{
	FILE	stats;
	char	*str;

	stats = *fopen("push_swap.time", "w+");
	str = ft_itoa((long long)(end - begin));
	fputs(str, &stats);
	free(str);
	fclose(&stats);
}

void	ft_solve_wrapper(t_stack *stack)
{
	ft_check_duplicates(*stack);
	if (ft_solve_small(*stack) == 1)
		return ;
	if (ft_is_solved(*stack) == 1)
		return ;
	if (stack->a[0] > stack->a[1] && stack->a[2] > stack->a[3])
		*stack = ft_start_pa_pa_ss(*stack);
	else if (stack->a[0] > stack->a[1])
		*stack = ft_sa(*stack);
	while ((stack->a[0] > stack->b[0] || stack->b_size == 0) \
			&& stack->a_size > 2)
		*stack = ft_pb(*stack);
	ft_solve_b(stack);
	ft_finish(stack);
}

int		main(int argc, char **argv)
{
	t_stack	stack;
	clock_t	begin;
	clock_t	end;
	int		flag;

	flag = 0;
	begin = clock();
	ft_validate_arguments(argc, argv);
	if (argc == 2)
	{
		flag = 1;
		argv = ft_is_string(&argc, argv);
	}
	if (argc == 2)
		return (0);
	ft_stack_init(&stack, argc, argv);
	if (flag == 1)
		ft_free_array((void**)argv, argc);
	ft_solve_wrapper(&stack);
	end = clock();
	ft_stats(begin, end);
	free(stack.a);
	free(stack.b);
	return (stack.op_count > 254 ? 255 : stack.op_count);
}
