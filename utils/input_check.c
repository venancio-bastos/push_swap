/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:44:52 by vebastos          #+#    #+#             */
/*   Updated: 2026/01/01 18:54:28 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int process_args(char **arr)
{
    int     j;
    long    num;

    j = 0;
    while (arr[j])
    {
        if (!is_number(arr[j]))
            return (0);
            
        num = ft_atol(arr[j]);
        if (num > INT_MAX || num < INT_MIN)
            return (0);
        j++;
    }
    return (1);
}