/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_argo_a_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:39:11 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/29 17:15:28 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_argo_a_to_b(t_stack *stack)
{
	int	max;
	int	i;

	max = 0;
	while (stack->a != NULL && ps_node_len(stack->a) > 3)
	{
		i = 0;
		while (stack->a != NULL && ps_node_len(stack->a) > 3 && i < 16)
		{
			if (max <= stack->a->num && stack->a->num < max + 8)
			{
				ps_stack_op("pb", stack);
				i++;
			}
			else if (max + 8 <= stack->a->num && stack->a->num < max + 16)
			{
				ps_stack_op("pb", stack);
				ps_stack_op("rb", stack);
				i++;
			}
			else
				ps_stack_op("ra", stack);
		}
		max += 16;
	}
}
