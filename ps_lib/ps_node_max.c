/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_node_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:31:33 by yushsato          #+#    #+#             */
/*   Updated: 2023/12/01 18:34:28 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ps_node_max(t_node *node)
{
	t_node	*max;

	max = node;
	while (node != NULL)
	{
		if (max->num < node->num)
			max = node;
		node = node->next;
	}
	return (max);
}
