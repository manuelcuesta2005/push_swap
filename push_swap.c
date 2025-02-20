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

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1)
		return(0);
	stack_a.head = NULL;
	stack_a.size = 0;
	stack_b.head = NULL;
	stack_b.size = 0;
	get_all_numbers(&stack_a, argv + 1);
	sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
