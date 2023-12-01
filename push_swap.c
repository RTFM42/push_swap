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
	ps_argo_a_to_b(stack);
	ps_argo_adjust_a_3(stack);
	ps_stack_free(stack);
	ps_argo_b_to_a(stack);
	ps_put_op("EOL");
}
