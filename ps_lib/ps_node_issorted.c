/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_node_issorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:40:56 by yushsato          #+#    #+#             */
/*   Updated: 2023/12/01 19:43:21 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_node_issorted(t_node *node)
{
	while (node != NULL)
	{
		if (node->next == NULL)
			break ;
		if (node->next->num > node->num)
			node = node->next;
		else
			return (0);
	}
	return (1);
}
