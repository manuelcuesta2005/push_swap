/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:07:54 by mcuesta-          #+#    #+#             */
/*   Updated: 2025/02/11 14:10:21 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	*get_numbers_array(char **argv, int count)
{
	t_stack	temp_stack;
	int		*numbers;
	int		i;
	t_node	*current;

	i = 0;
	if (count <= 0)
		return (NULL);
	temp_stack.head = NULL;
	temp_stack.size = 0;
	get_all_numbers(&temp_stack, argv + 1);
	numbers = (int *)malloc(sizeof(int) * count);
	if (!numbers)
	{
		free_stack(&temp_stack);
		ft_error("Error\n");
	}
	current = temp_stack.head;
	while (current)
	{
		numbers[i++] = current->content;
		current = current->next;
	}
	free_stack(&temp_stack);
	return (numbers);
}

void	start_stack(t_stack *stack_a, t_stack *stack_b, int *array, int count)
{
	t_node	*current;
	int		i;

	stack_a->head = NULL;
	stack_a->tail = NULL;
	stack_a->size = 0;
	stack_b->head = NULL;
	stack_b->tail = NULL;
	stack_b->size = 0;
	i = 0;
	while (i < count)
	{
		push_stacks(stack_a, 0, array[i]);
		i++;
	}
	insertion(array, count);
	current = stack_a->head;
	while (current)
	{
		current->index_stack = ft_index(current->content, array);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		count;
	int		*array;

	if (argc == 1)
		return (0);
	count = count_numbers(argc, argv);
	array = get_numbers_array(argv, count);
	start_stack(&stack_a, &stack_b, array, count);
	sort(&stack_a, &stack_b, array, count);
	free(array);
	free_stack(&stack_a);
	return (0);
}
