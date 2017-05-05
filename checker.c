/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 09:56:01 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/07 09:56:01 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		ft_parse_operations(t_stack stack, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		stack = ft_swap_a(stack);
	if (ft_strcmp(line, "sb") == 0)
		stack = ft_swap_b(stack);
	if (ft_strcmp(line, "ss") == 0)
		stack = ft_swap_ab(stack);
	if (ft_strcmp(line, "pa") == 0)
		stack = ft_push_a(stack);
	if (ft_strcmp(line, "pb") == 0)
		stack = ft_push_b(stack);
	if (ft_strcmp(line, "ra") == 0)
		stack = ft_rotate_a(stack);
	if (ft_strcmp(line, "rb") == 0)
		stack = ft_rotate_b(stack);
	if (ft_strcmp(line, "rr") == 0)
		stack = ft_rotate_ab(stack);
	if (ft_strcmp(line, "rra") == 0)
		stack = ft_rrotate_a(stack);
	if (ft_strcmp(line, "rrb") == 0)
		stack = ft_rrotate_b(stack);
	if (ft_strcmp(line, "rrr") == 0)
		stack = ft_rrotate_ab(stack);
	return (stack);
}

t_stack		ft_parse_wrapper(t_stack stack, char **line)
{
	int	temp;

	temp = stack.op_count;
	if (stack.debug == 1)
		ft_debug_wait(stack);
	while (temp != 0)
	{
		stack = ft_parse_operations(stack, *line);
		line++;
		temp--;
		if (stack.debug == 1)
			ft_debug_wait(stack);
	}
	return (stack);
}

void		ft_read_stdin(char **line, t_stack *stack)
{
	while (get_next_line(0, &line[stack->op_count]) != 0)
	{
		if (L("sa") && L("sb") && L("ss") && L("pa") && L("pb") && L("ra") \
	&& L("rb") && L("rr") && L("rra") && L("rrb") && L("rrr"))
			ft_print_error();
		stack->op_count++;
	}
}

void		ft_check(t_stack stack, char **line)
{
	ft_check_duplicates(stack);
	ft_read_stdin(line, &stack);
	stack = ft_parse_wrapper(stack, line);
	free(line);
	ft_check_solution(stack);
	if (stack.stats == 1)
		ft_read_stats(stack);
}

int			main(int argc, char **argv)
{
	t_stack	stack;
	char	**line;
	int		flag;

	flag = 0;
	if (ft_options(&argc, argv, &stack) == -1)
		exit(-1);
	ft_validate_arguments(argc, argv);
	if (argc == 2)
	{
		argv = ft_is_string(&argc, argv);
		flag = 1;
	}
	line = ft_memalloc(sizeof(char*) * (argc * ft_sq_rt(argc)));
	ft_stack_init(&stack, argc, argv);
	if (flag == 1)
		ft_free_array((void**)argv, argc);
	ft_check(stack, line);
	if (stack.op_count >= 1)
		free(line);
	remove("push_swap.time");
	free(stack.a);
	free(stack.b);
	return (stack.op_count > 254 ? 255 : stack.op_count);
}
