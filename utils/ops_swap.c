/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:43:55 by vebastos          #+#    #+#             */
/*   Updated: 2026/01/12 16:44:09 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;
	int	tmp_value;
	int	tmp_index;

	if (!head || !*head || !(*head)->next)
		return;
	first = *head;
	second = first->next;
	tmp_value = first->value;
	first->value = second->value;
	second->value = tmp_value;
	tmp_index = first->index;
	first->index = second->index;
	second->index = tmp_index;
}

void    sa(t_stack **stack_a)
{
    swap(stack_a);
    write(1, "sa\n", 3);
}

void    sb(t_stack **stack_b)
{
    swap(stack_b);
    write(1, "sb\n", 3);
}

void    ss(t_stack **stack_a, t_stack **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    write(1, "ss\n", 3);
}