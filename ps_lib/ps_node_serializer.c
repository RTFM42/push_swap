/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_node_serializer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:29:15 by yushsato          #+#    #+#             */
/*   Updated: 2023/12/07 20:53:26 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "limits.h"

static int	exitforce(int i)
{
	exit(i);
	return (1);
}

t_node	*ps_node_serializer(char **val)
{
	t_node			*ret;
	t_node			*current;
	static t_node	*prev;
	static int		i = -1;
	int				j;

	while (val[++i] != NULL)
	{
		current = ft_calloc(1, sizeof(t_node));
		current->prev = prev;
		if (prev != NULL)
			prev->next = current;
		else
			ret = current;
		prev = current;
		j = -1;
		while (val[++j] != NULL)
			if (ft_atoi(val[i]) > ft_atoi(val[j]))
			{
				if (current->num == INT_MAX)
					ft_printf("Error\n", exitforce(1));
				current->num += 1;
			}
	}
	return (ret);
}
