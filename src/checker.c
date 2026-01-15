/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 22:46:42 by vebastos          #+#    #+#             */
/*   Updated: 2026/01/15 22:46:44 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../utils/gnl/get_next_line.h"

void	error_exit(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	parse_command(t_stack **a, t_stack **b, char *line)
{
	if (!ft_checker_strcmp(line, "sa\n"))
		sa(a, false);
	else if (!ft_checker_strcmp(line, "sb\n"))
		sb(b, false);
	else if (!ft_checker_strcmp(line, "ss\n"))
		ss(a, b, false);
	else if (!ft_checker_strcmp(line, "pa\n"))
		pa(a, b, false);
	else if (!ft_checker_strcmp(line, "pb\n"))
		pb(b, a, false);
	else if (!ft_checker_strcmp(line, "ra\n"))
		ra(a, false);
	else if (!ft_checker_strcmp(line, "rb\n"))
		rb(b, false);
	else if (!ft_checker_strcmp(line, "rr\n"))
		rr(a, b, false);
	else if (!ft_checker_strcmp(line, "rra\n"))
		rra(a, false);
	else if (!ft_checker_strcmp(line, "rrb\n"))
		rrb(b, false);
	else if (!ft_checker_strcmp(line, "rrr\n"))
		rrr(a, b, false);
	else
		error_exit(a, b);
}

void	process_commands(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		parse_command(a, b, line);
		free(line);
		line = get_next_line(0);
	}
}

int	parse_arg(t_stack **a, char *av)
{
	char	**arr;

	arr = ft_split(av, ' ');
	if (!arr || !process_args(a, arr))
	{
		if (arr)
			free_matrix(arr);
		free_stack(a);
		write(2, "Error\n", 6);
		return (0);
	}
	free_matrix(arr);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	i = 1;
	while (i < ac)
	{
		if (!parse_arg(&a, av[i++]))
			return (1);
	}
	process_commands(&a, &b);
	if (stack_sorted(a) && stack_len(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
