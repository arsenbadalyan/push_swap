/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:33:45 by arsbadal          #+#    #+#             */
/*   Updated: 2023/03/03 20:27:37 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

// Libraries
# include <stdio.h>

// Stuctures
typedef struct s_list {
	int				data;
	size_t			index;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_stack
{
	size_t			top;
	struct s_list	*first;
	struct s_list	*last;
	char			name;
	short			has_error;
}	t_stack;

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// >>>>>>>>>> Functions <<<<<<<<<<
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// Print commands function
void			print_command(char first, char sec);
void			print_command_adn(char first, char sec, char additional);

void			print_stack(t_stack *stack);
t_stack			*init_stack(char name);
void			create_stack(int *list, size_t size, t_stack *istack);
void			index_stack(t_list *stack, size_t size);
void			sort_list(int *stack, size_t size);
void			indexing_stack(t_list *stack, int *temp, size_t size);
void			free_stack(t_stack *stack);

// Operations
void			swap(t_stack *stack, short idf);
void			swap_together(t_stack *stack_a, t_stack *stack_b, short idf);
void			push_stack(t_stack **fromStack, t_stack *toStack, short idf);
void			rotate(t_stack *stack, short idf);
void			rotate_together(t_stack *s1, t_stack *s2, short idf);
void			reverse(t_stack *stack, short idf);
void			reverse_together(t_stack *s1, t_stack *s2, short idf);
void			make_stack_empty(t_stack *stack);
void			pop(t_stack *istack, t_list **p_stack);
void			push(t_stack *istack, t_list *stack);

// If All is ok then start sort :)
void			sel_alg(t_stack *stack_a, t_stack *stack_b);
void			sort_3(t_stack *stack_a);
short			check_if_sorted(t_stack *stack);
short			check_ssort(t_stack *stack);
void			butterfly(t_stack *stack_a, t_stack *stack_b);
void			butterfly_reverse(t_stack *stack_a, t_stack *stack_b);
void			go_top(t_stack *stack, t_list *cur);
void			small_sort(t_stack *stack_a, t_stack *stack_b);
// Get N
size_t			get_n(size_t i);
size_t			ft_ln(size_t nb);
size_t			ft_sqrt(size_t nb);

#endif