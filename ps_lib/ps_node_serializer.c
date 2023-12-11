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
#include "unistd.h"
#include "limits.h"

static void	exit_with_error(int i)
{
	write(1, "Error\n", 6);
	exit(i);
}

t_node	*ps_node_serializer(char **val)
{
	t_node	*ret;
	t_node	*current;
	t_node	*prev;
	int		i;
	int		j;

	prev = NULL;
	i = -1;
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
			if (ft_atoi(val[i]) > ft_atoi(val[j]) && current->num++)
				if (current->num - 1 == INT_MAX)
					exit_with_error(1);
	}
	return (ret);
}
