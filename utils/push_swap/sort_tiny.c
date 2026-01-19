/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 15:25:05 by vebastos          #+#    #+#             */
/*   Updated: 2026/01/19 13:28:14 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_tiny(t_stack **a)
{
	t_stack	*biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, true);
	else if ((*a)->next == biggest_node)
		rra(a, true);
	if ((*a)->value > (*a)->next->value)
		sa(a, true);
}
