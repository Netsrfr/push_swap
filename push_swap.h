/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 10:57:18 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/06 10:57:18 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include "libft/libft.h"
# include "libraries/ft_printf/ft_printf.h"
# include "libraries/get_next_line/get_next_line.h"
# define L(x) (ft_strcmp(line[stack->op_count], x) != 0)

typedef struct		s_stack
{
	int		*a;
	int		a_size;
	int		a_min;
	int		a_max;
	int		*b;
	int		b_size;
	int		b_min;
	int		b_max;
	int		op_count;
	int		debug;
	int		stats;
}					t_stack;

typedef struct		s_debug
{
	int		a;
	int		b;
	int		a_size;
	int		b_size;
}					t_debug;

typedef struct		s_sort
{
	int		a_rot;
	int		a_rrot;
	int		b_rot;
	int		b_rrot;
	int		a_index;
	int		b_index;
	int		small;
	int		a_dir;
	int		b_dir;
}					t_sort;

t_stack				ft_swap_a(t_stack stack);
t_stack				ft_swap_b(t_stack stack);
t_stack				ft_swap_ab(t_stack stack);
t_stack				ft_push_a(t_stack stack);
t_stack				ft_push_b(t_stack stack);

t_stack				ft_rotate_a(t_stack stack);
t_stack				ft_rotate_b(t_stack stack);
t_stack				ft_rotate_ab(t_stack stack);

t_stack				ft_rrotate_a(t_stack stack);
t_stack				ft_rrotate_b(t_stack stack);
t_stack				ft_rrotate_ab(t_stack stack);

t_stack				ft_sa(t_stack stack);
t_stack				ft_ss(t_stack stack);
t_stack				ft_pa(t_stack stack);
t_stack				ft_pb(t_stack stack);

t_stack				ft_ra(t_stack stack);
t_stack				ft_rb(t_stack stack);
t_stack				ft_rr(t_stack stack);

t_stack				ft_rra(t_stack stack);
t_stack				ft_rrb(t_stack stack);
t_stack				ft_rrr(t_stack stack);

void				ft_print_error(void);
void				ft_validate_arguments(int argc, char **argv);
void				ft_stack_init(t_stack *stack, int argc, char **argv);
void				ft_check_duplicates(t_stack stack);
void				ft_check_solution(t_stack stack);

void				ft_convert_string(char **argv, char **str, int count);
char				**ft_update_argv(char **argv, char **str, int count);
char				**ft_is_string(int *argc, char **argv);
void				ft_free_array(void **array, int count);

void				ft_a_outbound(int value, t_stack *stack, int i);
void				ft_b_outbound(int value, t_stack *stack, int i);
void				ft_b_inbound(int value, t_stack *stack);
void				ft_a_inbound(int value, t_stack *stack);

int					ft_options(int *argc, char **argv, t_stack *stack);
void				ft_debug_init(t_debug debug, t_stack stack);
void				ft_debug_print(t_stack stack);
void				ft_debug_wait(t_stack stack);

int					ft_b_index(t_stack *stack, int i);
int					ft_a_index(t_stack *stack, int i);

void				ft_solve_b(t_stack *stack);
void				ft_solve_wrapper(t_stack *stack);
int					ft_solve_small(t_stack stack);

void				ft_calc_shortest(t_sort *sort);
t_sort				ft_fill_sort_a(t_stack *stack, t_sort sort, int i);
t_sort				ft_fill_sort_b(t_stack *stack, t_sort sort, int i);
int					ft_in_order(t_stack *stk);
int					ft_is_solved(t_stack stack);

void				ft_forwards(t_stack *stack, t_sort *sort);
void				ft_reverse(t_stack *stack, t_sort *sort);
void				ft_opposite(t_stack *stack, t_sort *sort);
void				ft_finish(t_stack *stack);
t_stack				ft_start_pa_pa_ss(t_stack stack);

int					ft_single_arg(int *argc, char **argv);
int					ft_dual_arg(int *argc, char **argv, int i);
int					ft_dual_flag(int *argc, char **argv);
int					ft_single_flag(int *argc, char **argv);
int					ft_options(int *argc, char **argv, t_stack *stack);

void				ft_read_stats(t_stack stack);
void				ft_print_stats(t_stack stack, double t, int ms);

int					ft_a_insert(t_stack *stack, int i, int j);
#endif
