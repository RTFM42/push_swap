/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:02:55 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/27 14:38:10 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_lib/push_swap.h"

void	push_swap(char **val)
{
	t_stack	*stack;

	stack = ft_calloc(1, sizeof(t_stack));
	stack->a = ps_node_serializer(val);
	if (ps_node_issorted(stack->a))
		;
	else if (ps_node_len(stack->a) <= 2 && stack->a->num > stack->a->next->num)
		ps_stack_op("sa", stack);
	else if (ps_node_len(stack->a) == 3)
		ps_argo_adjust_a_3(stack);
	else if (ps_node_len(stack->a) <= 5)
		ps_argo_adjust_a_5(stack);
	else
		ps_argo_all(stack);
	ps_stack_free(stack);
	ps_put_op("EOL");
}
