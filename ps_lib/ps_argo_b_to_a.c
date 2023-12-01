/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_argo_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:27:45 by yushsato          #+#    #+#             */
/*   Updated: 2023/12/01 19:21:44 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_argo_b_to_a(t_stack *stack)
{
	int		len;
	int		loc;
	t_node	*max;
	t_node	*tmp;

	while (stack->b != NULL)
	{
		len = ps_node_len(stack->b);
		max = ps_node_max(stack->b);
		loc = ps_node_len(max);
		tmp = max->prev;
		if (!!tmp && tmp->num + 1 == max->num && loc + 1 == len)
			ps_stack_op("pa pa sa", stack);
		else if (loc == len)
			ps_stack_op("pa", stack);
		else if (len - loc + 1 < loc)
			ps_stack_op("rb", stack);
		else if (len - loc + 1 >= loc)
			ps_stack_op("rrb", stack);
	}
}
