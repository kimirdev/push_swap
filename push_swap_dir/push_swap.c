/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdebbie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 04:38:02 by bdebbie           #+#    #+#             */
/*   Updated: 2019/12/07 04:39:09 by bdebbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stack *a, t_stack *b)
{
	int i;

	i = -1;
	if (b->size > 0)
		return (0);
	while (++i < a->size - 1)
		if (a->arr[i] < a->arr[i + 1])
			return (0);
	return (1);
}

int		main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;

	if (argc < 2)
		return (0);
	if (argc == 2)
		a = parse_string(argv[1]);
	else
		a = parse_arguments(++argv, --argc);
	b = (t_stack*)malloc(sizeof(t_stack));
	b->size = 0;
	b->arr = (int*)malloc(sizeof(int) * a->size);
	if (is_sorted(a, b))
		exit(0);
	if (a->size <= 10)
		sort_less_10(a, b);
	else if (a->size <= 120 && a->size >= 80)
		sort_100(a, b);
	else
		sort(a, b);
	free(a->arr);
	free(a);
	free(b->arr);
	free(b);
	return (0);
}
