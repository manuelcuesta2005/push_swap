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
	stack->head = header->next;
	header->next = stack_push->head;
	stack_push->head = header;
	stack->size--;
	stack_push->size++;
	if (move_stack == 'a')
		ft_printf("pa\n");
	else if (move_stack == 'b')
		ft_printf("pb\n");
}

void	rotate(t_stack *stack, char move_stack)
{
	t_node	*head;
	t_node	*bottom;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	head = stack->head;
	stack->head = head->next;
	bottom = stack->head;
	while (bottom->next)
		bottom = bottom->next;
	bottom->next = head;
	head->next = NULL;
	if (move_stack == 'a')
		ft_printf("ra\n");
	else if (move_stack == 'b')
		ft_printf("rb\n");
	else
		ft_printf("rr\n");
}

void	reverse_rotate(t_stack *stack, char move_stack)
{
	t_node	*head;
	t_node	*bottom;

	if (!stack || !stack->head || !stack->head->next)
		return ;
	head = stack->head;
	bottom = stack->head->next;
	while (bottom->next)
	{
		head = bottom;
		bottom = bottom->next;
	}
	head->next = NULL;
	bottom->next = stack->head;
	stack->head = bottom;
	if (move_stack == 'a')
		ft_printf("rra\n");
	else if (move_stack == 'b')
		ft_printf("rrb\n");
	else
		ft_printf("rrr\n");
}
