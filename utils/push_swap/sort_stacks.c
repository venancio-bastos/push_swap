/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:20:49 by vebastos          #+#    #+#             */
/*   Updated: 2026/01/15 18:33:20 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_middle)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_middle)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = *a;
	while (cheapest_node && !cheapest_node->cheapest)
		cheapest_node = cheapest_node->next;
	if (!cheapest_node)
		return ;
	if (cheapest_node->above_middle && cheapest_node->target_node->above_middle)
	{
		while (*b != cheapest_node->target_node && *a != cheapest_node)
			rr(a, b);
		current_index(*a);
		current_index(*b);
	}
	else if (!(cheapest_node->above_middle)
		&& !(cheapest_node->target_node->above_middle))
	{
		while (*b != cheapest_node->target_node && *a != cheapest_node)
			rrr(a, b);
		current_index(*a);
		current_index(*b);
	}
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match_index)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	min_on_top(t_stack **a)
{
	t_stack	*min_node;

	min_node = find_min(*a);
	while ((*a)->value != min_node->value)
	{
		if (min_node->above_middle)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		current_index(*a);
		current_index(*b);
		set_target_b(*a, *b);
		prep_for_push(a, (*b)->target_node, 'a');
		pa(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
