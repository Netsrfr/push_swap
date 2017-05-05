/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfeffer <jpfeffer@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 13:27:19 by jpfeffer          #+#    #+#             */
/*   Updated: 2017/04/11 13:27:19 by jpfeffer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_convert_string(char **argv, char **str, int count)
{
	int	i;
	int	j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i <= count)
	{
		str[i] = ft_memalloc(sizeof(char) * 11);
		i++;
	}
	i = 0;
	while (argv[1][k])
	{
		str[i][j] = argv[1][k];
		j++;
		k++;
		if (argv[1][k] == ' ')
		{
			k++;
			i++;
			j = 0;
		}
	}
}

char	**ft_update_argv(char **argv, char **str, int count)
{
	int	i;

	i = 0;
	argv = ft_memalloc(sizeof(char*) * count + 1);
	while (i <= count)
	{
		argv[i + 1] = ft_strdup(str[i]);
		i++;
	}
	return (argv);
}

char	**ft_is_string(int *argc, char **argv)
{
	char	**str;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == ' ')
			count++;
		i++;
	}
	if (count != 0)
	{
		*argc = count + 2;
		str = ft_memalloc(sizeof(char*) * count + 1);
		ft_convert_string(argv, str, count);
		argv = ft_update_argv(argv, str, count);
		ft_free_array((void**)str, *argc - 1);
	}
	return (argv);
}

void	ft_free_array(void **array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
