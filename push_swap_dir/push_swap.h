/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdebbie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 22:07:12 by bdebbie           #+#    #+#             */
/*   Updated: 2020/01/08 23:49:13 by bdebbie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct	s_stack
{
	int			*arr;
	int			size;
}				t_stack;

t_stack			*parse_string(char *str);
t_stack			*parse_arguments(char **argv, int argc);
void			reverse(t_stack **elem, char *str);
void			rotate(t_stack **elem, char *str);
void			swap(t_stack **elem, char *str);
void			push(t_stack **from, t_stack **to, char *str);
void			error_case(void);
void			sort(t_stack *a, t_stack *b);
int				median(t_stack *elem, int size);
void			sort_100(t_stack *a, t_stack *b);
int				is_min(int *arr, int size, int num);
int				is_max(int *arr, int size, int num);
int				is_any_less(t_stack *a, int size, int num);
void			exec_b(t_stack *a, t_stack *b, int mid);
void			div_act(int top, int bot, t_stack *a, t_stack *b);
int				ft_atoi(const char *str);
void			sort_less_10(t_stack *a, t_stack *b);
void			sort_ver(t_stack *a, t_stack *b);

#endif
