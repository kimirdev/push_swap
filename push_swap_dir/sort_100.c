/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdebbie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:06:59 by bdebbie           #+#    #+#             */
/*   Updated: 2020/01/07 23:09:07 by bdebbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	divide_a(t_stack *a, t_stack *b, int size)
{
	int mid;

	mid = median(a, size);
	while (is_any_less(a, a->size, mid))
	{
		if (a->arr[a->size - 1] >= mid)
			rotate(&a, "ra");
		else if (a->arr[a->size - 1] < mid)
			push(&a, &b, "pb");
	}
}

static void	divide_b(t_stack *a, t_stack *b)
{
	int mid;
	int top;
	int bot;

	mid = median(b, b->size);
	while (b->size > 0)
	{
		bot = -1;
		top = b->size;
		while (++bot < a->size)
			if (b->arr[bot] >= mid || is_min(b->arr, b->size, b->arr[bot])
				|| is_max(b->arr, b->size, b->arr[bot]))
				break ;
		while (--top > 0)
			if (b->arr[top] >= mid || is_min(b->arr, b->size, b->arr[top])
				|| is_max(b->arr, b->size, b->arr[top]))
				break ;
		div_act(top, bot, a, b);
	}
	while (a->arr[a->size - 1] < mid)
		rotate(&a, "ra");
}

void		sort_100(t_stack *a, t_stack *b)
{
	int i;
	int mid;
	int mid2;

	divide_a(a, b, a->size);
	divide_b(a, b);
	i = 0;
	mid = median(a, a->size);
	while (a->arr[a->size - 1] < mid)
		push(&a, &b, "pb");
	exec_b(a, b, mid);
	mid2 = median(a, a->size / 2);
	while (a->arr[a->size - 1] >= mid)
		if (a->arr[a->size - 1] < mid2)
			push(&a, &b, "pb");
		else
			rotate(&a, "ra");
	while (a->arr[0] > mid)
		reverse(&a, "rra");
	exec_b(a, b, mid2);
	while (a->arr[a->size - 1] >= mid2)
		push(&a, &b, "pb");
	exec_b(a, b, INT_MIN);
	while (a->arr[a->size - 1] >= mid2)
		rotate(&a, "ra");
}
