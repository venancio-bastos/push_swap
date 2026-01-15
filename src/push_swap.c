/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:35:06 by vebastos          #+#    #+#             */
/*   Updated: 2026/01/15 17:14:08 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_choice(t_stack **a, t_stack **b)
{
	if (stack_len(*a) == 2)
		sa(a);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else
		sort_stacks(a, b);
}

static int	parse_arg(t_stack **a, char *av)
{
	char	**arr;

	arr = ft_split(av, ' ');
	if (!arr)
		return (0);
	if (!process_args(a, arr))
	{
		free_matrix(arr);
		return (0);
	}
	free_matrix(arr);
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (1);
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (i < ac)
	{
		if (!parse_arg(&stack_a, av[i]))
		{
			free_stack(&stack_a);
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	if (!stack_sorted(stack_a))
		sort_choice(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
