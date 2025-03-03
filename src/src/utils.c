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

int	count_numbers(int argc, char **argv)
{
	int		i;
	int		count;
	char	**split_result;
	int		j;

	count = 0;
	i = 1;
	while (i < argc)
	{
		split_result = ft_split(argv[i], ' ');
		if (!split_result)
			ft_error("Error\n");
		j = 0;
		while (split_result[j])
		{
			if (is_valid_number(split_result[j]))
				count++;
			else
				return (free_split(split_result), ft_error("Error\n"), 0);
			j++;
		}
		free_split(split_result);
		i++;
	}
	return (count);
}

void	ft_error(char *string)
{
	ft_printf("%s", string);
	exit(EXIT_FAILURE);
}
