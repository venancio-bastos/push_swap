/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:45:29 by vebastos          #+#    #+#             */
/*   Updated: 2026/01/15 21:15:33 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = stack_last(*stack);
	last_node = tmp->prev;
	last_node->next = NULL;
	tmp->next = *stack;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	*stack = tmp;
}

void	rra(t_stack **stack_a, bool print)
{
	reverse_rotate(stack_a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, bool print)
{
	reverse_rotate(stack_b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, bool print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print)
		write(1, "rrr\n", 4);
}
