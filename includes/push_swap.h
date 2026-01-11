/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:35:44 by vebastos          #+#    #+#             */
/*   Updated: 2026/01/07 01:58:54 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif 

typedef struct		s_stack
{
	int	value;
	int index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

//main
void print_stack(t_stack *stack);
//ft_split
char	*copy_next_word(char const *s, char c, int *i);
void	free_split(char **arr, int index);
int	get_words(char const *s, char c);
char	**ft_split(char const *s, char c);
//input_check
int	is_number(char *str);
int process_args(t_stack **stack, char **arr);
int	check_duplicates(t_stack *stack, int num);
//stack_utils
t_stack	*stack_new(int content);
t_stack	*stack_lst(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new_node);
void	free_stack(t_stack **stack);
//utils_lib
long	ft_atol(const char	*str);
int	ft_strlen(const char *str);
void    free_matrix(char **arr);


#endif