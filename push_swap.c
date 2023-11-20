/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:02:55 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/19 19:21:21 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_node	*ps_parse(int size, char **val)
// {
// }

void	push_swap(char **val)
{
	int	i;

	i = 0;
	while (val[i] != NULL)
		ft_printf("%s, ", val[i++]);
	ft_printf("%s\n", val[i]);
}
