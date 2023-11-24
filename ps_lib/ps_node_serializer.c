/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_node_serializer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:29:15 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/24 18:29:16 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (ft_atoi(val[i]) > ft_atoi(val[j]))
				current->num += 1;
	}
	return (ret);
}
