/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:58:30 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/13 20:02:37 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// __attribute__((destructor))	static void	destructor(void)
// {
// 	system("leaks -q push_swap");
// }

static int	is_num(char *num)
{
	if (*num == 48 && *(num + 1) == '\0')
		return (1);
	if (*num == '-')
		num++;
	if (49 <= *num && *num <= 59)
	{
		while (48 <= *num && *num <= 59)
			num++;
		if (*num == '\0')
			return (1);
	}
	return (0);
}

static int	is_parsable(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc >= 2)
	{
		argv++;
		i = 0;
		while (i < argc - 1)
		{
			if (!is_num(argv[i]))
				return (0);
			j = 0;
			while (j < argc - 1)
			{
				if (!ft_memcmp(argv[i], argv[j], ft_strlen(argv[i]) + 1)
					&& i != j)
					return (0);
				j++;
			}
			i++;
		}
	}
	return (1);
}

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
	int		i;

	if (argc == 1)
		return (0);
	if (!is_parsable(argc, argv))
	{
		ft_printf("Error\n");
		return (1);
	}
	parsed = parser(argc, argv);
	ordered = order(parsed);
	push_swap(ordered);
	i = 0;
	while (parsed[i] != NULL)
		free(parsed[i++]);
	free(parsed[i]);
	free(parsed);
	free(ordered);
	return (0);
}
