/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:14:30 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/24 18:01:10 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_print_stack(t_stack stack)
{
	t_node	*a;
	t_node	*b;

	a = stack.a;
	b = stack.b;
	ft_printf("\n\x1b[33m----- stack [a] -----\nprev\t\tindex\t\tnext\n");
	while (a != NULL)
	{
		if (a->prev)
			ft_printf("%p\t%d\t\t%p\n", a->prev, a->num, a->next);
		else
			ft_printf("%p\t\t%d\t\t%p\n", a->prev, a->num, a->next);
		a = a->next;
	}
	ft_printf("----- stack [b] -----\nprev\t\tindex\t\tnext\n");
	while (b != NULL)
	{
		if (b->prev)
			ft_printf("%p\t%d\t\t%p\n", b->prev, b->num, b->next);
		else
			ft_printf("%p\t\t%d\t\t%p\n", b->prev, b->num, b->next);
		b = b->next;
	}
	ft_printf("----- stack end -----\x1b[0m\n");
}
