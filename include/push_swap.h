/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:39:17 by arsbadal          #+#    #+#             */
/*   Updated: 2023/03/03 20:27:16 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// >>>>>>>>>> Libraries <<<<<<<<<<
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "Stack.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// >>>>>>>>>> Functions <<<<<<<<<<
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// Utilites
// void		print_error(void);
void		free_me(void **addr, char **addr_2D);
char		**ft_split(const char *s, char c); // in one file
char		**splited_arr(char *str, char seperator);
size_t		length(char *str);
void		free_error(t_stack *a, t_stack *b);

// Checking
long long	my_atoi(char *number);
short		check_helper(char **argv, int argc, int *num_list, size_t *temp);
int			*mkarr_check_doubles(char **argv, int argc, size_t size);
int			check_doubles(int *num_list, size_t size);
size_t		validate_arguments(int argc, char **argv);
char		*check_zeros(char *number);
short		check(char *str);

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// >>>>>>>>>>> Checker <<<<<<<<<<<
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
int			ft_strncmp(const char *str1, const char *str2, size_t n);
char		**copy_list(char **list, char *line);
char		**get_lines(char *line, char **list);
short		true_arrangement(t_stack *stack);
void		select_function(t_stack *a, t_stack *b, char *command);
void		check_sort(t_stack *stack_a, char **commands);
short		check_input(int argc, char **argv, char **commands);

#endif