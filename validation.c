/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 14:31:55 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/07 14:31:55 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_error(void)
{
	write(2, "\x1b[31mError\x1b[39m\n", 16);
	exit(-1);
}

/*
** Validates input is only integers, '-' for negative numbers, and whitespace
*/

void	ft_validate_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc <= 1)
		exit(0);
	while (i < argc)
	{
		while (argv[i][j])
		{
			if ((argv[i][j] >= '0' && argv[i][j] <= '9') || argv[i][j] == ' ')
				j++;
			else if (argv[i][j] == '-' &&
					argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9')
				j++;
			else
				ft_print_error();
		}
		j = 0;
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			ft_print_error();
		i++;
	}
}

void	ft_stack_init(t_stack *stack, int argc, char **argv)
{
	int	i;

	i = 0;
	stack->a = ft_memalloc(sizeof(int) * argc - 1);
	stack->b = ft_memalloc(sizeof(int) * argc - 1);
	while (++i < argc)
	{
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return ;
		stack->a[i - 1] = (int)ft_atoi(argv[i]);
	}
	i = 1;
	stack->a_size = argc - 1;
	stack->a_min = stack->a[0];
	stack->a_max = stack->a[0];
	stack->b_size = 0;
	stack->op_count = 0;
	while (i < stack->a_size)
	{
		if (stack->a[i] < stack->a_min)
			stack->a_min = stack->a[i];
		if (stack->a[i] > stack->a_max)
			stack->a_max = stack->a[i];
		i++;
	}
}

/*
** Checks for duplicate numbers and numbers beyond range of int_min to int_max
*/

void	ft_check_duplicates(t_stack stack)
{
	int i;
	int j;

	if (stack.a_size == 1)
		exit(1);
	i = 0;
	j = 1;
	while (i < stack.a_size - 1)
	{
		while (j < stack.a_size)
		{
			if (stack.a[i] == stack.a[j])
				ft_print_error();
			j++;
		}
		i++;
		j = i + 1;
	}
}

void	ft_check_solution(t_stack stack)
{
	int	i;

	i = 0;
	if (stack.b_size != 0)
	{
		write(1, "\x1b[31mKO\x1b[39m\n", 13);
		exit(0);
	}
	else
	{
		while (i < stack.a_size - 1)
		{
			if (stack.a[i] > stack.a[i + 1])
			{
				write(1, "\x1b[31mKO\x1b[39m\n", 13);
				exit(0);
			}
			i++;
		}
	}
	write(1, "OK\n", 3);
}
