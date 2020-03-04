/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdebbie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 05:05:52 by bdebbie           #+#    #+#             */
/*   Updated: 2019/12/08 05:05:53 by bdebbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_stack **elem, char *str)
{
	int	buff;
	int i;

	i = 0;
	buff = (*elem)->arr[0];
	while (i++ < (*elem)->size - 1)
		(*elem)->arr[i - 1] = (*elem)->arr[i];
	(*elem)->arr[(*elem)->size - 1] = buff;
	i = 0;
	if (str)
	{
		while (str[i] != '\0')
			write(1, &str[i++], 1);
		write(1, "\n", 1);
	}
}

void	rotate(t_stack **elem, char *str)
{
	int	buff;
	int i;

	i = (*elem)->size - 1;
	buff = (*elem)->arr[(*elem)->size - 1];
	while (i > 0)
	{
		(*elem)->arr[i] = (*elem)->arr[i - 1];
		i--;
	}
	(*elem)->arr[0] = buff;
	i = 0;
	if (str)
	{
		while (str[i] != '\0')
			write(1, &str[i++], 1);
		write(1, "\n", 1);
	}
}

void	swap(t_stack **elem, char *str)
{
	int buff;
	int i;

	if ((*elem)->size < 2)
		return ;
	buff = (*elem)->arr[(*elem)->size - 1];
	(*elem)->arr[(*elem)->size - 1] = (*elem)->arr[(*elem)->size - 2];
	(*elem)->arr[(*elem)->size - 2] = buff;
	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}

void	push(t_stack **from, t_stack **to, char *str)
{
	int i;

	if ((*from)->size == 0)
		return ;
	(*to)->arr[(*to)->size] = (*from)->arr[(*from)->size - 1];
	(*from)->arr[(*from)->size - 1] = 0;
	(*to)->size++;
	(*from)->size--;
	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	write(1, "\n", 1);
}
