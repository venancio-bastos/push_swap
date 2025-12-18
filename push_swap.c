/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:35:06 by vebastos          #+#    #+#             */
/*   Updated: 2025/12/18 15:12:40 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;	
	}
	return (1);
}


int	main(int ac, char **av)
{
	int		i;
	int		j;
	long	num;
	char	**arr;

	i = 1;   
	while (i < ac)
	{
		arr = ft_split(av[i], ' ');
		if (!arr)
			return (0);
		j = 0;
		if (!is_number(arr[j]))
		{
			free(arr);
			printf("Error valid number\n");
			return (1);
		}
		num = ft_atol(arr[j]);
		if (num > INT_MAX || num < INT_MIN)
		{
			free(arr);
			printf("Error more bits then int\n");
			return (0);
		}
		free(arr);
		i++;
	}
	return (0);
}
