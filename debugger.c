/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugger.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 10:34:47 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/18 10:34:47 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Checks for debug flag and if found removes flag from argv and reduces argc
** accordingly.
*/

void	ft_debug_init(t_debug debug, t_stack stack)
{
	ft_printf("   A   |   B   \n______ | ______\n");
	while (debug.a_size > debug.b_size)
	{
		ft_printf("%6d |       \n", stack.a[debug.a]);
		debug.a_size--;
		debug.a++;
	}
	while (debug.b_size > debug.a_size)
	{
		ft_printf("       | %-6d\n", stack.b[debug.b]);
		debug.b_size--;
		debug.b++;
	}
	while (debug.a_size > 0)
	{
		ft_printf("%6d | %-6d\n", stack.a[debug.a], stack.b[debug.b]);
		debug.a_size--;
		debug.a++;
		debug.b++;
	}
	ft_printf("\n");
}

/*
** Wrapper for debug printing function. Function names for debug_print and
** debug_init are swapped so the wrapper is called when debug_print is wanted.
*/

void	ft_debug_print(t_stack stack)
{
	t_debug	debug;

	debug.a = 0;
	debug.b = 0;
	debug.a_size = stack.a_size;
	debug.b_size = stack.b_size;
	ft_debug_init(debug, stack);
}

void	ft_debug_wait(t_stack stack)
{
	char	buffer;

	ft_debug_print(stack);
	read(1, &buffer, 1);
}
