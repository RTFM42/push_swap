/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_put_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 22:08:57 by yushsato          #+#    #+#             */
/*   Updated: 2023/11/29 22:26:02 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_put_op(char *op)
{
	static char	*ptr = NULL;
	char		*tmp;

	if (ft_memcmp(op, "EOL", 4))
	{
		if (ptr == NULL)
			ptr = ft_strdup(op);
		else
		{
			tmp = ptr;
			ptr = ft_calloc(1, ft_strlen(ptr) + 1 + ft_strlen(op) + 1);
			ft_memcpy(ptr, tmp, ft_strlen(tmp));
			ft_memcpy(ptr + ft_strlen(tmp), "\n", 1);
			ft_memcpy(ptr + ft_strlen(tmp) + 1, op, ft_strlen(op));
			free(tmp);
		}
	}
	else
	{
		ft_printf("%s\n", ptr);
		free(ptr);
		ptr = NULL;
	}
}
