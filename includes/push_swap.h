/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:35:44 by vebastos          #+#    #+#             */
/*   Updated: 2026/01/15 22:32:35 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif 

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	bool			above_middle;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		ft_checker_strcmp(const char *s1, const char *s2);
void	parse_command(t_stack **a, t_stack **b, char *line);
void	sort_choice(t_stack **a, t_stack **b);
int		parse_arg(t_stack **a, char *av);
long	ft_atol(const char	*str);
int		ft_strlen(const char *str);
void	free_matrix(char **arr);
t_stack	*stack_new(int content);
t_stack	*stack_last(t_stack *stack);
void	stack_add_back(t_stack **stack, t_stack *new_node);
void	free_stack(t_stack **stack);
bool	stack_sorted(t_stack *stack);
int		is_number(char *str);
int		process_args(t_stack **stack, char **arr);
int		check_duplicates(t_stack *stack, int num);
char	*copy_next_word(char const *s, char c, int *i);
void	free_split(char **arr, int index);
int		get_words(char const *s, char c);
char	**ft_split(char const *s, char c);
void	set_target_a(t_stack *a, t_stack *b);
void	cost_analysis_a(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *stack);
void	init_nodes_a(t_stack *a, t_stack *b);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void	move_a_to_b(t_stack **a, t_stack **b);
void	set_target_b(t_stack *a, t_stack *b);
void	sort_stacks(t_stack **a, t_stack **b);
void	min_on_top(t_stack **a);
void	sort_three(t_stack **a);
int		stack_len(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);
void	current_index(t_stack *stack);
void	swap(t_stack **head);
void	sa(t_stack **stack_a, bool print);
void	sb(t_stack **stack_b, bool print);
void	ss(t_stack **stack_a, t_stack **stack_b, bool print);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a, bool print);
void	rrb(t_stack **stack_b, bool print);
void	rrr(t_stack **stack_a, t_stack **stack_b, bool print);
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a, bool print);
void	rb(t_stack **stack_b, bool print);
void	rr(t_stack **stack_a, t_stack **stack_b, bool print);
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **stack_a, t_stack **stack_b, bool print);
void	pb(t_stack **stack_a, t_stack **stack_b, bool print);

#endif