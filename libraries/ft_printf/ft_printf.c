/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:25:47 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/01/17 14:25:47 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_init(void)
{
	g_fl.error = 0;
	g_fl.precision = 0;
	g_fl.precision_v = 0;
	g_fl.neg = 0;
	g_fl.count = 0;
	g_fl.pound = 0;
	g_fl.zero = 0;
	g_fl.minus = 0;
	g_fl.plus = 0;
	g_fl.space = 0;
	g_fl.width = 0;
	g_fl.width_v = 0;
	g_fl.h = 0;
	g_fl.hh = 0;
	g_fl.l = 0;
	g_fl.ll = 0;
	g_fl.j = 0;
	g_fl.z = 0;
}

char	*ft_flags(char *progress)
{
	while (PR('+') || PR('-') || PR('#') || PR(' ') || PR('h') || PR('l')
	|| PR('j') || PR('z') || (*progress >= '0' && *progress <= '9'))
	{
		if (*progress >= '1' && *progress <= '9')
			progress = ft_flags_width(progress);
		if (*progress == '+')
			progress = ft_flags_plus(progress);
		if (*progress == '-')
			progress = ft_flags_minus(progress);
		if (*progress == '0')
			progress = ft_flags_zero(progress);
		if (*progress == '#')
			progress = ft_flags_pound(progress);
		if (*progress == ' ')
			progress = ft_flags_space(progress);
		if (*progress == 'h')
			progress = ft_flags_h(progress);
		if (*progress == 'l')
			progress = ft_flags_l(progress);
		if (*progress == 'j' || *progress == 'z')
			progress = ft_flags_jz(progress);
	}
	progress = ft_flags_precision(progress);
	return (progress);
}

int		parser(const char *format, va_list arguments)
{
	char	*fmt_ptr;

	fmt_ptr = (char*)format;
	while (*fmt_ptr)
	{
		if (*fmt_ptr == '%')
		{
			flag_init();
			fmt_ptr = ft_flags(++fmt_ptr);
			fmt_ptr = ft_conversions(arguments, fmt_ptr);
		}
		if (g_print)
		{
			g_return = ft_strlen(g_print) + g_return;
			ft_putstr(g_print);
			g_print = 0;
		}
		while (*fmt_ptr && *fmt_ptr != '%')
		{
			ft_putchar(*fmt_ptr++);
			g_return++;
		}
	}
	return (1);
}

ssize_t	ft_printf(const char *format, ...)
{
	va_list	arguments;

	if (g_fl.error == -1)
		return (-1);
	g_return = 0;
	va_start(arguments, format);
	parser(format, arguments);
	va_end(arguments);
	return (g_return);
}
