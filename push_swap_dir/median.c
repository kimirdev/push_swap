/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdebbie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 20:57:34 by bdebbie           #+#    #+#             */
/*   Updated: 2019/12/15 21:03:03 by bdebbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		median(t_stack *elem, int size)
{
	int n;
	int m;
	int i;
	int j;

	i = elem->size - size;
	while (i < elem->size)
	{
		j = elem->size - size - 1;
		n = 0;
		m = 0;
		while (++j < elem->size)
			if (elem->arr[j] > elem->arr[i])
				n++;
			else if (elem->arr[j] < elem->arr[i])
				m++;
		if (size % 2 == 0)
			n++;
		if (n == m)
			return (elem->arr[i]);
		i++;
	}
	return (0);
}
