/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 15:56:44 by mcuesta-          #+#    #+#             */
/*   Updated: 2025/02/17 15:56:58 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	rot_sort(t_stack *stack, int min_index_stack)
{
	int	a;
	int	b;
	int	c;

	(void)min_index_stack;
	a = stack->head->content;
	b = stack->head->next->content;
	c = stack->head->next->next->content;
	if (a < b && b < c)
		return (1);
	if (b < c && a > c)
		return (1);
	if (c < a && a < b)
		return (1);
	return (0);
}

void	simple_sort(t_stack *stack_a, int length)
{
	int	min_value_stack;
	int	r;

	if (check_order(stack_a))
		return ;
	min_value_stack = min_value(stack_a);
	r = count_r(stack_a->head, min_value_stack);
	if (rot_sort(stack_a, min_value_stack))
	{
		if (r < length - r)
			rotate(stack_a, 'a');
		else
			reverse_rotate(stack_a, 'a');
	}
	else
	{
		swap(stack_a, 'a');
		if (check_order(stack_a))
			return ;
		if (r < length - r)
			rotate(stack_a, 'a');
		else
			reverse_rotate(stack_a, 'a');
	}
}

void	insertion_sort(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	minimun_value;
	int	i;
	int	n;

	i = 0;
	n = length;
	while (i < n - 3 && stack_a->size > 1)
	{
		minimun_value = min_value(stack_a);
		if (count_r(stack_a->head, minimun_value) <= n - minimun_value
			- count_r(stack_a->head, minimun_value))
			while (stack_a->head->content != minimun_value)
				rotate(stack_a, 'a');
		else
			while (stack_a->head->content != minimun_value)
				reverse_rotate(stack_a, 'a');
		push(stack_a, stack_b, 'b');
		length--;
	}
	simple_sort(stack_a, length);
	i = 0;
	while (stack_b->size > 0)
		push(stack_b, stack_a, 'a');
}

void	k_sort1(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(length) * 14 / 10;
	while (stack_a->head)
	{
		if (stack_a->head->content <= 1)
		{
			push(stack_a, stack_b, 'b');
			rotate(stack_b, 'b');
			i++;
		}
		else if (stack_a->head->content <= i + range)
		{
			push(stack_a, stack_b, 'b');
			i++;
		}
		else
			rotate(stack_a, 'a');
	}
}

void	k_sort2(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	rb_count;
	int	rrb_count;

	while (length - 1 >= 0)
	{
		rb_count = count_r(stack_a->head, length - 1);
		rrb_count = (length - 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stack_a->head->content != length - 1)
				rotate(stack_b, 'b');
			push(stack_b, stack_a, 'a');
			length--;
		}
		else
		{
			while (stack_b->head->content != length - 1)
				reverse_rotate(stack_b, 'b');
			push(stack_b, stack_a, 'a');
			length--;
		}
	}
}
