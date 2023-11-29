/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_op_rev_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:18:26 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/24 19:18:27 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ps_stack_op_rev_rotate(t_node *node)
{
	t_node	*isolate;

	if (node == NULL || node->next == NULL)
		return (node);
	node = ps_node_last(node);
	isolate = node;
	node->prev->next = NULL;
	node = ps_node_first(node->prev);
	node->prev = isolate;
	isolate->prev = NULL;
	isolate->next = node;
	return (isolate);
}
