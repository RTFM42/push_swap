/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_node_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:29:01 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/24 18:29:03 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
