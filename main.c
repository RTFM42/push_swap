/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:58:30 by yushsato          #+#    #+#             */
/*   Updated: 2023/12/07 17:06:07 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib/push_swap.h"

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
		if (val[i][0] == '-' && val[i][1] != '\0')
			n++;
		if ('1' <= val[i][n] && val[i][n] <= '9')
			while ('0' <= val[i][n] && val[i][n] <= '9')
				n++;
		if (val[i][n] != '\0')
			return (0);
	}
	return (1);
}

static void	strs_free(char **ary)
{
	int	i;

	i = -1;
	while (ary[++i] != NULL)
		free(ary[i]);
	free(ary[i]);
	free(ary);
}

static char	**strs_dup(char **src, unsigned int len)
{
	char			**val;
	unsigned int	i;

	i = -1;
	val = ft_calloc(len + 1, sizeof(char **));
	while (++i < len)
		val[i] = ft_strdup(src[i]);
	return (val);
}

int	main(int argc, char **argv)
{
	char	**val;
	int		flag;

	if (argc <= 1)
		return (0);
	if (argc == 2)
		val = ft_split(argv[1], ' ');
	else
		val = strs_dup(&argv[1], argc - 1);
	flag = is_valid(val);
	if (flag)
		push_swap(val);
	else
		ft_printf("Error\n");
	if (val != NULL)
		strs_free(val);
	return (!flag);
}
