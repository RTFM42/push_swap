/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:02:55 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/27 14:16:26 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib/push_swap.h"

void	push_swap(char **val)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	stack->a = ps_node_serializer(val);
	ps_print_stack(*stack);
	ps_stack_op("sa", stack);
	ps_print_stack(*stack);
	ps_stack_op("pa", stack);
	ps_print_stack(*stack);
	ps_stack_op("pa", stack);
	ps_print_stack(*stack);
	ps_stack_op("sb", stack);
	ps_print_stack(*stack);
	ps_stack_op("ra", stack);
	ps_print_stack(*stack);
	ps_stack_free(stack);
}
