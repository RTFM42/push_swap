/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_op_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 19:18:00 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/24 19:18:19 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ps_stack_op_push(t_node *src, t_node *dest)
{
	t_node	*isolate;

	if (src == NULL)
		return (NULL);
	isolate = src;
	src = src->next;
	if (src != NULL)
		src->prev = NULL;
	if (dest != NULL)
		dest->prev = isolate;
	isolate->next = dest;
	return (src);
}

t_stack	ps_stack_op_push_wrapper(char *op, t_stack stack)
{
	t_node	*tmp;

	if (ft_strncmp(op, "pa", 3) == 0)
	{
		tmp = stack.a;
		stack.a = ps_stack_op_push(stack.b, stack.a);
		stack.b = tmp;
	}
	if (ft_strncmp(op, "pb", 3) == 0)
	{
		tmp = stack.b;
		stack.b = ps_stack_op_push(stack.a, stack.b);
		stack.a = tmp;
	}
	return (stack);
}
