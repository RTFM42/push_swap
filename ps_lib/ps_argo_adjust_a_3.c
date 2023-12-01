/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_argo_adjust_a_3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:20:23 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/30 18:21:39 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_argo_adjust_a_3(t_stack *stack)
{
	int	n1;
	int	n2;
	int	n3;

	if (ps_node_len(stack->a) != 3)
		return ;
	n1 = stack->a->num;
	n2 = stack->a->next->num;
	n3 = stack->a->next->next->num;
	if (n1 < n2 && n2 < n3)
		return ;
	if (n1 < n2 && n2 > n3 && n1 < n3)
		ps_stack_op("sa ra", stack);
	if (n1 > n2 && n2 < n3 && n1 < n3)
		ps_stack_op("sa", stack);
	if (n1 < n2 && n2 > n3 && n1 > n3)
		ps_stack_op("rra", stack);
	if (n1 > n2 && n2 > n3 && n1 > n3)
		ps_stack_op("sa rra", stack);
	if (n1 > n2 && n2 < n3 && n1 > n3)
		ps_stack_op("ra", stack);
}
