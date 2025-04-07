/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ../push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuesta- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:18:09 by mcuesta-          #+#    #+#             */
/*   Updated: 2025/02/05 19:18:14 by mcuesta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stddef.h>
# include <stdlib.h>

typedef struct s_node
{
	int				content;
	int				index_stack;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*head;
	int				size;
	t_node			*tail;
}					t_stack;

// stack management
void				push_stacks(t_stack *stack, int index, int content);
int					pop_stacks(t_stack *stack);
void				free_stack(t_stack *stack);
// operations
void				swap(t_stack *stack, char move_stack);
void				push(t_stack *stack, t_stack *stack_push, char move_stack);
void				rotate(t_stack *stack, char move_stack);
void				rotate_rr(t_stack *stack_a, t_stack *stack_b);
void				reverse_rotate(t_stack *stack, char move_stack);
// parse arguments
int					is_valid_number(const char *str);
void				get_numbers_by_string(t_stack *stack, char *string,
						int *index);
void				get_numbers_by_arguments(t_stack *stack, char *argv,
						int *index);
void				get_all_numbers(t_stack *stack, char **argv);
int					check_duplicate(t_stack *stack, char *argv);
int					check_order(t_stack *stack);
void				ft_error(char *string);
// utils algorithms
int					min_index(t_stack *stack);
int					count_r(t_node *content, int index);
void				insertion(int array[], int n);
void				sort(t_stack *stack_a, t_stack *stack_b, int *array,
						int length);
// algorithm
int					rot_sort(t_stack *stack, int min_index_stack);
void				simple_sort(t_stack *stack_a, int length);
void				insertion_sort(t_stack *stack_a, t_stack *stack_b,
						int length);
void				k_sort1(t_stack *stack_a, t_stack *stack_b, int length);
void				k_sort2(t_stack *stack_a, t_stack *stack_b, int length);
// add libft
int					count_numbers(int argc, char **argv);
void				free_split(char **split_result);
#endif