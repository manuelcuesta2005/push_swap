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
		return (EXIT_FAILURE);
	index = stack->head;
	min_value = index->content;
	while (index->next)
	{
		index = index->next;
		if (index->content < min_value)
			min_value = index->content;
	}
	return (min_value);
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
