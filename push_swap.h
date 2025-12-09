/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:35:44 by vebastos          #+#    #+#             */
/*   Updated: 2025/12/09 13:38:36 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_stack
{
	int	value;
	int	index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int	ft_atoi(char *c);



#endif