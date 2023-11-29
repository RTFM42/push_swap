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

static void	to_top(t_stack *stack, int max, int count)
{
	int i;

	i = 0;
	while (stack->a != NULL && i < 8)
	{
		if (max - 8 <= stack->a->num && stack->a->num < max && i < count)
		{
			ps_stack_op("pb", stack);
			i++;
		}
		else
			ps_stack_op("rra", stack);
	}
}

static void to_bottom(t_stack *stack, int max, int count)
{
	int i;

	i = 0;
	while (stack->a != NULL && i < 8)
	{
		if (max - 8 <= stack->a->num && stack->a->num < max && i < count)
		{
			ps_stack_op("pb", stack);
			ps_stack_op("rrb", stack);
			i++;
		}
		else
			ps_stack_op("rra", stack);
	}
}

void	ps_argo_a_to_b(t_stack *stack)
{
	int	max;

	max = 8;
	ps_print_stack(*stack);
	while (stack->a != NULL)
	{
		to_top(stack, max, 8);
		max += 8;
		to_bottom(stack, max, 8);
	}
}
