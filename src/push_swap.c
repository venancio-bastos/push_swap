/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:35:06 by vebastos          #+#    #+#             */
/*   Updated: 2026/01/07 02:00:00 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	char	**arr;
	t_stack	*stack_a;
	
	if (ac < 2)
		return (0);
	i = 1;
	stack_a = NULL;
	while (i < ac)
	{
		arr = ft_split(av[i], ' ');
		if (!arr)
			return (0);
		if (!process_args(&stack_a, arr))
		{
			free_matrix(arr);
			free_stack(&stack_a);
			write(2, "Error\n", 6);
			return(1);
		}
		free_matrix(arr);
		i++;
	}
	print_stack(stack_a);
	return (0);
}

void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%d\n", stack->value);
        stack = stack->next;
    }
}
