/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:48:42 by mcuesta-          #+#    #+#             */
/*   Updated: 2025/02/05 20:48:45 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	swap(t_stack *stack, char move_stack)
{
	t_node	*first;
	t_node	*second;
	int		tmp_content;
	int		tmp_index;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	first = stack->head;
	second = first->next;
	tmp_content = first->content;
	tmp_index = first->index_stack;
	first->content = second->content;
	first->index_stack = second->index_stack;
	second->content = tmp_content;
	second->index_stack = tmp_index;
	if (!second->next)
		stack->tail = first;
	if (move_stack == 'a')
		ft_printf("sa\n");
	else if (move_stack == 'b')
		ft_printf("sb\n");
	else
		ft_printf("ss\n");
}

void	push(t_stack *stack, t_stack *stack_push, char move_stack)
{
	t_node	*header;

	if (!stack || !stack->head || !stack_push)
		return ;
	header = stack->head;
	stack->head = stack->head->next;
	if (stack->head)
		stack->head->prev = NULL;
	else
		stack->tail = NULL;
	stack->size--;
	header->next = stack_push->head;
	header->prev = NULL;
	if (stack_push->head)
		stack_push->head->prev = header;
	else
		stack_push->tail = header;
	stack_push->head = header;
	stack_push->size++;
	if (stack->size == 0)
		stack->head = NULL;
	if (move_stack == 'a')
		ft_printf("pa\n");
	else if (move_stack == 'b')
		ft_printf("pb\n");
}

void	rotate(t_stack *stack, char move_stack)
{
	t_node	*new_head;
	t_node	*old_head;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	old_head = stack->head;
	new_head = old_head->next;
	new_head->prev = NULL;
	stack->tail->next = old_head;
	old_head->prev = stack->tail;
	old_head->next = NULL;
	stack->head = new_head;
	stack->tail = old_head;
	if (move_stack == 'a')
		ft_printf("ra\n");
	else if (move_stack == 'b')
		ft_printf("rb\n");
}

void	rotate_rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a, 'r');
	rotate(stack_b, 'r');
	ft_printf("rr\n");
}

void	reverse_rotate(t_stack *stack, char move_stack)
{
	t_node	*new_tail;
	t_node	*old_tail;

	if (!stack || !stack->head || stack->size < 2)
		return ;
	old_tail = stack->tail;
	new_tail = old_tail->prev;
	new_tail->next = NULL;
	old_tail->prev = NULL;
	old_tail->next = stack->head;
	stack->head->prev = old_tail;
	stack->head = old_tail;
	stack->tail = new_tail;
	if (move_stack == 'a')
		ft_printf("rra\n");
	else if (move_stack == 'b')
		ft_printf("rrb\n");
	else
		ft_printf("rrr\n");
}
