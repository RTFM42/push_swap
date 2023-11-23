/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_node_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 21:05:14 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/23 14:06:56 by yushsato         ###   ########.fr       */
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

void	ps_node_free(t_node *node)
{
	t_node	*prev;
	t_node	*ptr;

	if (node == NULL)
		return ;
	prev = node->prev;
	while (node != NULL)
	{
		ptr = node->next;
		free(node);
		node = ptr;
	}
	while (prev != NULL)
	{
		ptr = prev->prev;
		free(prev);
		prev = ptr;
	}
}

t_node	*ps_node_first(t_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node->prev != NULL)
		node = node->prev;
	return (node);
}

t_node	*ps_node_last(t_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next != NULL)
		node = node->next;
	return (node);
}
