/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:44:17 by vebastos          #+#    #+#             */
/*   Updated: 2026/01/12 16:44:33 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last_node;

	if (!stack || !*stack || !(*stack)->next)
		return;
	tmp = *stack;
	last_node = stack_last(*stack);
	*stack = tmp->next;
	(*stack)->prev = NULL;
	last_node->next = tmp;
	tmp->prev = last_node;
	tmp->next = NULL;
}

void ra(t_stack **stack_a)
{
    rotate(stack_a);
    write(1, "ra\n", 3);
}

void rb(t_stack **stack_b)
{
    rotate(stack_b);
    write(1, "rb\n", 3);
}

void rr(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    write(1, "rr\n", 3);
}