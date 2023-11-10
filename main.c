/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:58:30 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/10 19:37:13 by yushsato         ###   ########.fr       */
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
		ret[i - 1] = n;
	}
	return (ret);
}

int	main(int argc, char **argv)
{
	char	**parsed;
	int		*ordered;

	parsed = parser(argc, argv);
	ordered = order(parsed);
	while (*ordered != 0)
		ft_printf("%d,", *ordered++);
	printf("%d", *ordered);
	exit (0);
	return (0);
}
