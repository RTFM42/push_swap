/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_op_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:18:45 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/24 19:18:46 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ps_stack_op_swap(t_node *node)
{
	t_node	*node_1;
	t_node	*node_2;
	t_node	*node_3;

	if (node == NULL || node->next == NULL)
		return (node);
	node_1 = node;
	node_2 = node->next;
	node_3 = node->next->next;
	node_2->prev = NULL;
	node_2->next = node_1;
	node_1->prev = node_2;
	node_1->next = node_3;
	if (node_3 != NULL)
		node_3 -> prev = node_1;
	return (node_2);
}
