/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_node_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:28:56 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/24 18:28:57 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ps_node_first(t_node *node)
{
	if (node == NULL)
		return (NULL);
	while (node->prev != NULL)
		node = node->prev;
	return (node);
}
