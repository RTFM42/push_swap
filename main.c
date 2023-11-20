/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:58:30 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/20 16:03:26 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

__attribute__((destructor))	static void	destructor(void)
{
	system("leaks -q push_swap");
}

static int	is_valid(char **val)
{
	int	i;
	int	n;
	int	z;

	i = -1;
	while (val[++i] != NULL)
	{
		n = 0;
		z = -1;
		while (val[++z] != NULL)
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
	char	**val;
	int		flag;
	int		i;

	if (argc <= 1)
		return (0);
	if (argc == 2)
		val = ft_split(argv[1], ' ');
	else
	{
		val = ft_calloc(argc, sizeof(char **));
		while (--argc >= 1)
			val[argc - 1] = ft_strdup(argv[argc]);
	}
	flag = is_valid(val);
	if (flag)
		push_swap(val);
	else
		ft_printf("Error\n");
	i = 0;
	while (val[i] != NULL)
		free(val[i++]);
	free(val[i]);
	free(val);
	return (!flag);
}
