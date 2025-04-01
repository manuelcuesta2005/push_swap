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

int	min_index(t_stack *stack)
{
	t_node	*index;
	int		min_index;

	if (!stack || !stack->head)
		return (0);
	index = stack->head;
	min_index = index->index_stack;
	while (index->next)
	{
		index = index->next;
		if (index->index_stack < min_index)
			min_index = index->index_stack;
	}
	return (min_index);
}

int	count_r(t_node *content, int index)
{
	int	i;

	i = 0;
	if (!content)
		return (EXIT_FAILURE);
	while (content && content->index_stack != index)
	{
		content = content->next;
		i++;
	}
	return (i);
}

void	insertion(int array[], int n)
{
	int	i;
	int	j;
	int	element;

	i = 1;
	while (i < n)
	{
		element = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > element)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = element;
		i++;
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b, int *array, int length)
{
	length = stack_a->size;
	if (check_order(stack_a))
	{
		free(array);
		free_stack(stack_a);
		ft_error("");
	}
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
		ft_error("Error\n");
}
