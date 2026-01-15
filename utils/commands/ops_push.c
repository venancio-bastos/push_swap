/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:44:53 by vebastos          #+#    #+#             */
/*   Updated: 2026/01/15 21:14:25 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*node_to_move;

	if (!*src)
		return ;
	node_to_move = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_move->next = NULL;
	if (!*dest)
	{
		*dest = node_to_move;
		node_to_move->next = NULL;
	}
	else
	{
		node_to_move->next = *dest;
		(*dest)->prev = node_to_move;
		*dest = node_to_move;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b, bool print)
{
	push(stack_b, stack_a);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_b, t_stack **stack_a, bool print)
{
	push(stack_a, stack_b);
	if (print)
		write(1, "pb\n", 3);
}
