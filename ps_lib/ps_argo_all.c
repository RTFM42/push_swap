/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_argo_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:39:11 by yushsato          #+#    #+#             */
/*   Updated: 2023/12/01 19:12:23 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_to_b(t_stack *stack)
{
	int	max;
	int	i;
	int s;

	s = ps_node_len(stack->a) / 10 + 1;
	max = 0;
	while (stack->a != NULL && ps_node_len(stack->a) > 0)
	{
		i = 0;
		while (stack->a != NULL && ps_node_len(stack->a) > 0 && i < s * 2)
		{
			if (max <= stack->a->num && stack->a->num < max + s)
			{
				ps_stack_op("pb", stack);
				i++;
			}
			else if (max + s <= stack->a->num && stack->a->num < max + s * 2)
			{
				ps_stack_op("pb rb", stack);
				i++;
			}
			else
				ps_stack_op("ra", stack);
		}
		max += s * 2;
	}
}

static void	b_to_a(t_stack *stack)
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

void	ps_argo_all(t_stack *stack)
{
	a_to_b(stack);
	b_to_a(stack);
}
