/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algorithms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:47:45 by mcuesta-          #+#    #+#             */
/*   Updated: 2025/02/16 15:47:46 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	min_value(t_stack *stack)
{
	t_node	*index;
	int		min_value;

	if (!stack || !stack->head)
		return (0);
	index = stack->head;
	min_value = index->content;
	while (index->next)
	{
		if (index->content < min_value)
			min_value = index->content;
		index = index->next;
	}
	return (min_value);
}

int	max_value(t_stack *stack)
{
	t_node	*index;
	int		max;

	if (!stack || !stack->head)
		return (0);
	index = stack->head;
	max = index->content;
	while (index)
	{
		if (index->content > max)
			max = index->content;
		index = index->next;
	}
	return (max);
}

int	count_r(t_node *content, int value)
{
	int	i;

	i = 0;
	if (!content)
		return (EXIT_FAILURE);
	while (content && content->content != value)
	{
		content = content->next;
		i++;
	}
	return (i);
}

int	find_smallest(t_stack *stack)
{
	t_node	*current;
	int		min_value;
	int		min_pos;
	int		i;

	if (!stack || !stack->head)
		return (-1);
	current = stack->head;
	min_value = current->content;
	min_pos = 0;
	i = 0;
	while (current)
	{
		if (current->content < min_value)
		{
			min_value = current->content;
			min_pos = i;
		}
		current = current->next;
		i++;
	}
	return (min_pos);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int	length;

	length = stack_a->size;
	if (check_order(stack_a))
		ft_error(stack_a);
	else if (length == 2)
		swap(stack_a, 'a');
	else if (length == 3)
		simple_sort(stack_a, length);
	else if (length <= 7)
		insertion_sort(stack_a, stack_b, length);
	else if (length > 7)
	{
		k_sort1(stack_a, stack_b, length);
		k_sort2(stack_a, stack_b, length);
	}
	else
		ft_error(stack_a);
}
