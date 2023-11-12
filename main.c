/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:58:30 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/12 18:32:30 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**parser(int argc, char **argv)
{
	char	**values;
	char	**ptr;

	if (argc == 2)
		values = ft_split(argv[1], ' ');
	else
	{
		ptr = ft_calloc(argc, sizeof(char *));
		values = ptr;
		while (--argc > 0)
			*ptr++ = ft_strdup(*(++argv));
	}
	return (values);
}

static int	is_include(int *ary, int *i)
{
	while (*ary != 0)
	{
		if (*ary == *i)
			return (1);
		ary++;
	}
	return (0);
}

static int	*order(char **c)
{
	int		*ret;
	int		i;
	int		j;
	int		n;

	i = 0;
	while (c[i++] != NULL)
		;
	ret = ft_calloc(sizeof(char *), i);
	i = 0;
	while (c[i++] != NULL)
	{
		j = 0;
		n = 1;
		while (c[j++] != NULL)
			if (ft_atoi(c[j - 1]) < ft_atoi(c[i - 1]))
				n++;
		while (is_include(ret, &n))
			n++;
		ret[i - 1] = n;
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	char	**parsed;
	int		*ordered;
	int		i;

	parsed = parser(argc, argv);
	ordered = order(parsed);
	i = 0;
	while (ordered[i])
		printf("%d, ", ordered[i++]);
	i = 0;
//	while (parsed[i] != NULL)
//		free(parsed[i++]);
//	free(parsed);
	return (0);
}
