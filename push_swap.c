/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:02:55 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/13 21:44:55 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_to_top(int *a, int *b, int min, int max)
{
	while (
}

void	find_to_bottom(int *a, int *b, int min, int max)
{

}

void	push_swap(int *stack_a)
{
	int	*stack_b;
	int	len;
	int	flag;
	int	max;
	int	min;

	len = 0;
	while (stack_a[len] != 0)
		len++;
	stack_b = ft_calloc(len + 1, sizeof(int));
	
}
