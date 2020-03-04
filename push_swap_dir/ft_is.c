/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdebbie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 21:22:46 by bdebbie           #+#    #+#             */
/*   Updated: 2020/01/11 21:22:50 by bdebbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_min(int *arr, int size, int num)
{
	int i;

	i = 0;
	while (i < size)
		if (num > arr[i++])
			return (0);
	return (1);
}

int		is_max(int *arr, int size, int num)
{
	int i;

	i = 0;
	while (i < size)
		if (num < arr[i++])
			return (0);
	return (1);
}

int		is_any_less(t_stack *a, int size, int num)
{
	int i;

	i = 0;
	while (size-- > 0)
		if (a->arr[a->size - size - 1] < num)
			return (1);
	return (0);
}

void	div_act(int top, int bot, t_stack *a, t_stack *b)
{
	if (bot >= (b->size - 1 - top))
		while (top++ < b->size - 1)
			rotate(&b, "rb");
	else
		while (bot-- >= 0)
			reverse(&b, "rrb");
	push(&b, &a, "pa");
	if (is_min(b->arr, b->size, a->arr[a->size - 1]))
		rotate(&a, "ra");
}

void	exec_b(t_stack *a, t_stack *b, int mid)
{
	int top;
	int bot;

	while (b->size > 0)
	{
		bot = -1;
		top = b->size;
		while (++bot < a->size)
			if (is_min(b->arr, b->size, b->arr[bot]) ||
				is_max(b->arr, b->size, b->arr[bot]))
				break ;
		while (--top > 0)
			if (is_min(b->arr, b->size, b->arr[top]) ||
				is_max(b->arr, b->size, b->arr[top]))
				break ;
		div_act(top, bot, a, b);
	}
	while (a->arr[a->size - 1] < mid)
		rotate(&a, "ra");
}
