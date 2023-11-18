/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:58:30 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/18 21:00:31 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// __attribute__((destructor))	static void	destructor(void)
// {
// 	system("leaks -q push_swap");
// }

int	is_parsable(int len, char **val)
{
	int	i;
	int	n;
	int	z;

	i = -1;
	while (++i < len)
	{
		n = 0;
		z = -1;
		while (++z < len)
			if (i != z && !ft_memcmp(val[i], val[z], ft_strlen(val[i]) + 1))
				return (0);
		if ('0' == val[i][0] && '\0' == val[i][1])
			continue ;
		if ((long)INT_MAX < ps_atoi(val[i]) || (long)INT_MIN > ps_atoi(val[i]))
			return (0);
		if (val[i][0] == '-')
			n++;
		if ('1' <= val[i][n] && val[i][n] <= '9')
			while ('0' <= val[i][n] && val[i][n] <= '9')
				n++;
		if (val[i][n] != '\0')
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	char			**val;
	unsigned int	size;

	if (argc <= 1)
		return (0);
	val = &argv[1];
	size = argc - 1;
	if (argc == 2)
	{
		size = 0;
		val = ft_split(argv[1], ' ');
		while (val[size] != NULL)
			size++;
	}
	if (is_parsable(size, val))
		ft_printf("OK\n");
	return (0);
}
