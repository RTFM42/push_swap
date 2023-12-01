/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:14:26 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/24 19:05:13 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handler(char *op, t_stack *stack)
{
	if (!ft_memcmp("sa", op, 3))
		stack->a = ps_stack_op_swap(stack->a);
	else if (!ft_memcmp("sb", op, 3))
		stack->b = ps_stack_op_swap(stack->b);
	else if (!ft_memcmp("pa", op, 3) && stack->b != NULL)
		*stack = ps_stack_op_push_wrapper("pa", *stack);
	else if (!ft_memcmp("pb", op, 3) && stack->a != NULL)
		*stack = ps_stack_op_push_wrapper("pb", *stack);
	else if (!ft_memcmp("ra", op, 3))
		stack->a = ps_stack_op_rotate(stack->a);
	else if (!ft_memcmp("rb", op, 3))
		stack->b = ps_stack_op_rotate(stack->b);
	else if (!ft_memcmp("rra", op, 4))
		stack->a = ps_stack_op_rev_rotate(stack->a);
	else if (!ft_memcmp("rrb", op, 4))
		stack->b = ps_stack_op_rev_rotate(stack->b);
	else
		return ;
	ps_put_op(op);
}

void	ps_stack_op(char *op, t_stack *stack)
{
	char	**ops;
	char	**tmp;

	ops = ft_split(op, ' ');
	tmp = ops;
	while (*ops != NULL)
	{
		handler(*ops, stack);
		free(*ops);
		ops++;
	}
	free(*ops);
	free(tmp);
}
