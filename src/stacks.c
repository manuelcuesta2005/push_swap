/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:11:03 by mcuesta-          #+#    #+#             */
/*   Updated: 2025/02/05 19:11:06 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	push_stacks(t_stack *stack, int index, int content)
{
	t_node	*tmp;
	t_node	*current;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		return ;
	tmp->content = content;
	tmp->index_stack = index;
	tmp->next = NULL;
	if (stack->head == NULL)
	{
		stack->head = tmp;
	}
	else
	{
		current = stack->head;
		while (current->next)
			current = current->next;
		current->next = tmp;
	}
	stack->size++;
}

int	pop_stacks(t_stack *stack)
{
	t_node	*top;
	int		content;

	if (!stack->head || !stack)
		return (0);
	top = stack->head;
	content = top->content;
	stack->head = top->next;
	free(top);
	stack->size--;
	return (content);
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	while (stack->head)
	{
		temp = stack->head;
		stack->head = stack->head->next;
		free(temp);
	}
}
