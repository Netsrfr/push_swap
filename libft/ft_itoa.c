/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 11:52:26 by jpfeffer          #+#    #+#             */
/*   Updated: 2016/09/28 11:52:26 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <printf.h>

char		*ft_itoa(long long int n)
{
	char	*str;
	int		i;

	i = (ft_mylog(n) - 1);
	if (!(str = ft_memalloc(sizeof(char) * ft_mylog(n) + 1)))
		return (0);
	str[ft_mylog(n)] = '\0';
	if (n == -9223372036854775807)
		ft_strcpy(str, "-9223372036854775807");
	if (n < 0 && n != -9223372036854775807)
	{
		str[0] = '-';
		n = (n * -1);
	}
	while (n >= 10)
	{
		str[i] = (n % 10 + 48);
		i--;
		n = (n / 10);
	}
	if (n < 10 && n != -9223372036854775807)
		str[i] = (n % 10 + 48);
	return (str);
}
