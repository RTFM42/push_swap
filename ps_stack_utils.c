/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:14:26 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/23 17:28:30 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*ps_stack_swap(t_node *node)
{
	t_node	*node_1;
	t_node	*node_2;
	t_node	*node_3;

	if (node == NULL || node->next == NULL)
		return (node);
	node_1 = node;
	node_2 = node->next;
	node_3 = node->next->next;
	node_2->prev = NULL;
	node_2->next = node_1;
	node_1->prev = node_2;
	node_1->next = node_3;
	if (node_3 != NULL)
		node_3 -> prev = node_1;
	return (node_2);
}

static t_node	*ps_stack_push(t_node *src, t_node *dest)
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

static t_node	*ps_stack_rotate(t_node *node)
{
	t_node	*isolate;

	if (node == NULL || node->next == NULL)
		return (node);
	isolate = node;
	node = node->next;
	node->prev = NULL;
	node = ps_node_last(node);
	node->next = isolate;
	isolate->next = NULL;
	isolate->prev = node;
	return (ps_node_first(node));
}

static t_node	*ps_stack_rev_rotate(t_node *node)
{
	t_node	*isolate;

	if (node == NULL || node->next == NULL)
		return (node);
	node = ps_node_last(node);
	isolate = node;
	node->prev->next = NULL;
	node = ps_node_first(node->prev);
	node->prev = isolate;
	isolate->prev = NULL;
	isolate->next = node;
	return (isolate);
}

void	ps_stack_op(char *op, t_stack *stack)
{
	t_node	*tmp;

	if (!ft_memcmp("sa", op, 3))
		stack->a = ps_stack_swap(stack->a);
	if (!ft_memcmp("sb", op, 3))
		stack->b = ps_stack_swap(stack->b);
	if (!ft_memcmp("pa", op, 3) && stack->a != NULL)
	{
		tmp = stack->a;
		stack->a = ps_stack_push(stack->a, stack->b);
		stack->b = tmp;
	}
	if (!ft_memcmp("pb", op, 3) && stack->b != NULL)
	{
		tmp = stack->b;
		stack->b = ps_stack_push(stack->b, stack->b);
		stack->a = tmp;
	}
	if (!ft_memcmp("ra", op, 3))
		stack->a = ps_stack_rotate(stack->a);
	if (!ft_memcmp("rb", op, 3))
		stack->b = ps_stack_rotate(stack->b);
	if (!ft_memcmp("rrb", op, 4))
		stack->b = ps_stack_rev_rotate(stack->b);
	ft_printf("%s", op);
}
