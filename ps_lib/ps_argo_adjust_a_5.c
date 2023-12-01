/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_argo_adjust_a_5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:56:52 by yushsato          #+#    #+#             */
/*   Updated: 2023/12/01 20:11:04 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_argo_adjust_a_5(t_stack *stack)
{
	int		loc;
	int		len;

	while (ps_node_len(stack->a) > 3)
	{
		len = ps_node_len(stack->a);
		loc = ps_node_len(ps_node_min(stack->a));
		if (loc == len)
			ps_stack_op("pb", stack);
		else if (len - loc + 1 < loc)
			ps_stack_op("rb", stack);
		else if (len - loc + 1 >= loc)
			ps_stack_op("rrb", stack);
	}
	ps_argo_adjust_a_5(stack);
	ps_stack_op("pa pa", stack);
	if (stack->a->next != NULL && stack->a->num > stack->a->next->num)
		ps_stack_op("sa");
}
