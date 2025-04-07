/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:55:14 by mcuesta-          #+#    #+#             */
/*   Updated: 2025/02/27 19:55:16 by mcuesta-         ###   ########.fr       */
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

void	simple_sort(t_stack *stack, int length)
{
	int	min_s_index;
	int	r;

	if (check_order(stack))
		return ;
	min_s_index = min_index(stack);
	r = count_r(stack->head, min_s_index);
	if (rot_sort(stack, min_s_index))
	{
		if (r < length - r)
			rotate(stack, 'a');
		else
			reverse_rotate(stack, 'a');
	}
	else
	{
		swap(stack, 'a');
		if (check_order(stack))
			return ;
		if (r < length - r)
			rotate(stack, 'a');
		else
			reverse_rotate(stack, 'a');
	}
}

void	insertion_sort(t_stack *stack_a, t_stack *stack_b, int length)
{
	int	min_index_stack;
	int	iter;
	int	n;

	iter = 0;
	n = length;
	while (iter++ < n - 3)
	{
		min_index_stack = min_index(stack_a);
		if (count_r(stack_a->head, min_index_stack) <= n - min_index_stack
			- count_r(stack_a->head, min_index_stack))
			while (stack_a->head->index_stack != min_index_stack)
				rotate(stack_a, 'a');
		else
			while (stack_a->head->index_stack != min_index_stack)
				reverse_rotate(stack_a, 'a');
		if (check_order(stack_a) && stack_b->size == 0)
			return ;
		push(stack_a, stack_b, 'b');
		length--;
	}
	simple_sort(stack_a, length);
	iter = 0;
	while (iter++ < n - 3)
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
		if (stack_a->head->index_stack <= i)
		{
			push(stack_a, stack_b, 'b');
			rotate(stack_b, 'b');
			i++;
		}
		else if (stack_a->head->index_stack <= i + range)
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
		rb_count = count_r(stack_b->head, length - 1);
		rrb_count = (length + 3) - rb_count;
		if (rb_count <= rrb_count)
		{
			while (stack_b->head->index_stack != length - 1)
				rotate(stack_b, 'b');
			push(stack_b, stack_a, 'a');
			length--;
		}
		else
		{
			while (stack_b->head->index_stack != length - 1)
				reverse_rotate(stack_b, 'b');
			push(stack_b, stack_a, 'a');
			length--;
		}
	}
}
