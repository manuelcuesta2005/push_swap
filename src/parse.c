/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:10:51 by mcuesta-          #+#    #+#             */
/*   Updated: 2025/02/11 14:11:07 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (str[i] == '0' && str[i + 1] != '\0' && !ft_isdigit(str[i + 1]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_split(char **split_result)
{
	int	i;

	i = 0;
	if (!split_result)
		return ;
	while (split_result[i])
		free(split_result[i++]);
	free(split_result);
}

void	get_numbers_by_string(t_stack *stack, char *string, int *index)
{
	int		i;
	long	num;
	char	**split_result;

	i = 0;
	split_result = ft_split(string, ' ');
	if (!split_result)
		return ;
	while (split_result[i])
	{
		if (!is_valid_number(split_result[i]))
			return (free_split(split_result), free_stack(stack),
				ft_error("Error\n"));
		num = ft_atol(split_result[i]);
		if (num > 2147483647 || num < -2147483648)
			return (free_split(split_result), free_stack(stack),
				ft_error("Error\n"));
		if (check_duplicate(stack, split_result[i]))
			return (free_split(split_result), free_stack(stack),
				ft_error("Error\n"));
		push_stacks(stack, (*index)++, (int)num);
		i++;
	}
	free_split(split_result);
}

void	get_numbers_by_arguments(t_stack *stack, char *argv, int *index)
{
	long	num;

	if (!argv || !stack)
		return ;
	if (!is_valid_number(argv))
		return (ft_error("Error\n"), free_stack(stack));
	num = ft_atol(argv);
	if (num > 2147483647 || num < -2147483648)
		return (ft_error("Error\n"), free_stack(stack));
	if (check_duplicate(stack, argv))
		return (ft_error("Error\n"), free_stack(stack));
	push_stacks(stack, (*index)++, (int)num);
}

void	get_all_numbers(t_stack *stack, char **argv)
{
	int			i;
	static int	index;

	i = 0;
	index = 0;
	if (!argv || !stack)
		return ;
	while (argv[i])
	{
		if (ft_strchr(argv[i], ' '))
			get_numbers_by_string(stack, argv[i], &index);
		else
			get_numbers_by_arguments(stack, argv[i], &index);
		if (stack->size == 0)
		{
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
