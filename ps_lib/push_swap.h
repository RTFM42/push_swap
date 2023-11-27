/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:03:13 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/27 14:12:40 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

typedef struct s_node
{
	int				num;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*a;
	t_node	*b;
}	t_stack;

void	push_swap(char **val);
char	**ps_split(const char *s, char c);
long	ps_atoi(const char *str);
t_node	*ps_node_serializer(char **val);
void	ps_node_free(t_node *node);
t_node	*ps_node_first(t_node *node);
t_node	*ps_node_last(t_node *node);
t_node	*ps_stack_op_push(t_node *src, t_node *dest);
t_node	*ps_stack_op_rev_rotate(t_node *node);
t_node	*ps_stack_op_rotate(t_node *node);
t_node	*ps_stack_op_swap(t_node *node);
t_stack	ps_stack_op_push_wrapper(char *op, t_stack stack);
void	ps_stack_op(char *op, t_stack *stack);
void	ps_stack_free(t_stack *stack);

void	ps_print_stack(t_stack stack);

#endif
