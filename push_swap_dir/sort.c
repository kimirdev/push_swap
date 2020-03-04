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

static void	divide_b(t_stack *a, t_stack *b, int b_size)
{
	int mid;
	int i;
	int point;

	mid = median(b, b->size);
	i = 0;
	while (i++ < b_size)
		if (b->arr[b->size - 1] < mid)
			rotate(&b, "rb");
		else
			push(&b, &a, "pa");
	point = b->size;
	if (b->size > 45)
		divide_b(a, b, b->size);
	if (b->size <= 45)
		exec_b(a, b, a->arr[a->size - 1]);
	if (b->size == 0)
		while (b_size > point++)
			push(&a, &b, "pb");
	if (b->size > 45)
		divide_b(a, b, b->size);
	if (b->size <= 45)
		exec_b(a, b, a->arr[a->size - 1]);
}

static void	divide_a(t_stack *a, t_stack *b, int size)
{
	int mid;
	int i;

	i = 0;
	mid = median(a, size);
	while (1)
	{
		if (a->arr[a->size - 1] >= mid && is_any_less(a, a->size, mid))
			rotate(&a, "ra");
		else if (a->arr[a->size - 1] < mid)
			push(&a, &b, "pb");
		if (!(is_any_less(a, a->size, mid)))
			break ;
	}
	divide_b(a, b, b->size);
}

static void	second_divide_a(t_stack *a, t_stack *b, int size, int q)
{
	int mid;
	int i;

	i = 0;
	mid = median(a, size++);
	while (1)
	{
		size--;
		if (a->arr[a->size - 1] >= mid && is_any_less(a, size, mid))
			rotate(&a, "ra");
		else if (a->arr[a->size - 1] < mid && a->arr[a->size - 1] >= q)
			push(&a, &b, "pb");
		if (!(is_any_less(a, size, mid)))
			break ;
	}
}

void		sort(t_stack *a, t_stack *b)
{
	int mid;

	mid = median(a, a->size);
	divide_a(a, b, a->size);
	second_divide_a(a, b, a->size / 2 + 1, mid);
	while (a->arr[0] > mid)
		reverse(&a, "rra");
	divide_b(a, b, b->size);
	while (a->arr[a->size - 1] > mid)
		push(&a, &b, "pb");
	divide_b(a, b, b->size);
	while (a->arr[a->size - 1] >= mid)
		rotate(&a, "ra");
}
