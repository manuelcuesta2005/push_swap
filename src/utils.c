/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:51:04 by mcuesta-          #+#    #+#             */
/*   Updated: 2025/02/14 15:51:05 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

long	ft_atol(const char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

int	ft_sqrt(int number)
{
	int	i;

	if (number < 4)
		return (1);
	i = 2;
	while (i * i < number)
		i++;
	if (i * i > number)
	{
		if ((i * i - number) < ((i - 1) * (i - 1) + (-number)))
			return (i);
	}
	return (i - 1);
}

int	check_duplicate(t_stack *stack, char *argv)
{
	t_node	*size_list;
	int		num;

	if (!stack || !argv)
		return (0);
	num = ft_atoi(argv);
	size_list = stack->head;
	while (size_list)
	{
		if (size_list->content == num)
			return (1);
		size_list = size_list->next;
	}
	return (0);
}

int	check_order(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->head || stack->size == 0)
		return (1);
	current = stack->head;
	while (current->next)
	{
		if (current->content < current->next->content)
			current = current->next;
		else
			return (0);
	}
	return (1);
}

void	ft_error(t_stack *stack)
{
	free_stack(stack);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
