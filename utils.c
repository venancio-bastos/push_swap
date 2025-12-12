/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:10:56 by vebastos          #+#    #+#             */
/*   Updated: 2025/12/09 19:47:27 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *c)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (c[i])
		result = (result * 10) + (c[i++] - '0');
	return (result);
}

char ft_split(char arr, char sep)
{
	int	i;
}