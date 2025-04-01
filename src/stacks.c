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
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return ;
	node->content = content;
	node->index_stack = index;
	node->next = NULL;
	node->prev = stack->tail;
	if (!stack->head)
		stack->head = node;
	else
		stack->tail->next = node;
	stack->tail = node;
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
	if (stack->head)
		stack->head->prev = NULL;
	else
		stack->tail = NULL;
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
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
}
