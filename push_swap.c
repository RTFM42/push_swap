/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:02:55 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/24 18:00:47 by yushsato         ###   ########.fr       */
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
	ps_node_free(stack->a);
	ps_node_free(stack->b);
	free(stack);
}
