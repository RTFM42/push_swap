/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:58:30 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/07 17:20:00 by yushsato         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char	**parsed;

	parsed = parser(argc, argv);
	while (*parsed != NULL)
		ft_printf("%s ", *parsed++);
	exit (0);
	return (0);
}
