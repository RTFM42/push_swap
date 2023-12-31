/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_uadd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yushsato <yushsato@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 01:21:34 by yushsato          #+#    #+#             */
/*   Updated: 2023/06/24 23:11:12 by yushsato         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extra.h"
#include <limits.h>

int	ex_uadd(int i1, int i2)
{
	if (i1 < 0 || i2 < 0)
		return (-1);
	while (i2 != 0)
	{
		if (i1 == INT_MAX && i2 > 0)
			return (-1);
		i1++;
		i2--;
	}
	return (i1);
}
