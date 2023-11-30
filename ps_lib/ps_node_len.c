/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_node_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:40:52 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/27 19:42:28 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_node_len(t_node *node)
{
	int	len;

	len = 0;
	while (node != NULL)
	{
		node = node->next;
		len++;
	}
	return (len);
}
