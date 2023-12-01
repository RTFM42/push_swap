/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_node_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:02:34 by yushsato          #+#    #+#             */
/*   Updated: 2023/12/01 20:03:51 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ps_node_min(t_node *node)
{
	t_node	*min;
	min = node;
	while (node != NULL)
	{
		if (min->num > node->num)
			min = node;
		node = node->next;
	}
	return (min);
}
