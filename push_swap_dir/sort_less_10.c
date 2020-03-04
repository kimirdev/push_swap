/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdebbie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 21:06:59 by bdebbie           #+#    #+#             */
/*   Updated: 2019/12/15 21:07:01 by bdebbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	bin_act(int top, int bot, t_stack **a, t_stack **b)
{
	if (bot >= ((*a)->size - 1 - top))
		while (top++ < (*a)->size - 1)
			rotate(a, "ra");
	else
		while (bot-- >= 0)
			reverse(a, "rra");
	push(a, b, "pb");
}

static void	binary_division(t_stack **a, t_stack **b)
{
	int mid;
	int top;
	int bot;
	int fixed_size;

	while ((*a)->size > 3)
	{
		mid = median(*a, (*a)->size);
		fixed_size = (*a)->size;
		while ((*a)->size > fixed_size / 2)
		{
			bot = -1;
			top = (*a)->size;
			while (++bot < (*a)->size)
				if ((*a)->arr[bot] > mid)
					break ;
			while (--top > 0)
				if ((*a)->arr[top] > mid)
					break ;
			if (bot - top == bot && bot == (*a)->size)
				break ;
			bin_act(top, bot, a, b);
		}
	}
}

static void	case_of_three(t_stack **a)
{
	if ((*a)->arr[1] < (*a)->arr[2] && (*a)->arr[1] < (*a)->arr[0]
		&& (*a)->arr[0] > (*a)->arr[2])
		swap(a, "sa");
	else if ((*a)->arr[2] > (*a)->arr[1] && (*a)->arr[2] > (*a)->arr[0]
		&& (*a)->arr[1] < (*a)->arr[0])
		rotate(a, "ra");
	else if ((*a)->arr[1] > (*a)->arr[2] && (*a)->arr[2] > (*a)->arr[0]
		&& (*a)->arr[0] < (*a)->arr[1])
		reverse(a, "rra");
	else if ((*a)->arr[2] > (*a)->arr[1] && (*a)->arr[2] > (*a)->arr[0]
		&& (*a)->arr[0] < (*a)->arr[1])
	{
		swap(a, "sa");
		reverse(a, "rra");
	}
	else if ((*a)->arr[2] < (*a)->arr[1] && (*a)->arr[2] < (*a)->arr[0]
		&& (*a)->arr[1] > (*a)->arr[0])
	{
		swap(a, "sa");
		rotate(a, "ra");
	}
}

void		sort_less_10(t_stack *a, t_stack *b)
{
	int mid;

	if (a->size > 3)
		binary_division(&a, &b);
	if (a->size == 2)
		if (a->arr[1] > a->arr[0])
			swap(&a, "sa");
	if (a->size == 3)
		case_of_three(&a);
	if (b->size > 0)
		exec_b(a, b, INT_MIN);
	mid = median(a, a->size);
	while (a->arr[a->size - 1] > mid)
		rotate(&a, "ra");
}
