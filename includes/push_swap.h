/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:35:44 by vebastos          #+#    #+#             */
/*   Updated: 2026/01/01 18:58:03 by vebastos         ###   ########.fr       */
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

int	is_number(char *str);
long	ft_atol(const char	*str);
char	**ft_split(char const *s, char c);
int	get_words(char const *s, char c);
char	*copy_next_word(char const *s, char c, int *i);
void	free_split(char **arr, int index);
int	ft_strlen(const char *str);
int process_args(char **arr);


#endif