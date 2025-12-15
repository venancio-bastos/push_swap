/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:35:06 by vebastos          #+#    #+#             */
/*   Updated: 2025/12/15 15:13:20 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	is_number(char **str)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (str[j])
	{
		while (str[j][i])
		{
			if (!(str[j][i] >= '0' && str[j][i] <= '9' && !(str[j][i] <= 32)))
			{
				printf("Error\n");
				return (0);
			}
			printf("Value: %c\n", str[j][i]);
			i++;
		}
		j++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_number(ft_split(av[i], ' ')))
		{
			printf("Error");
			//free stuff
		}
		i++;
	}
	return (0);
}