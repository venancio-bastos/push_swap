/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vebastos <vebastos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:10:56 by vebastos          #+#    #+#             */
/*   Updated: 2025/12/18 14:24:50 by vebastos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	ft_atol(const char	*str)
{
	long	result;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			sign = -1;
			i++;
		}
	}
	result = 0;
	while (str[i] <= 32)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
char	**ft_split(char const *s, char c)
{
	int		i;
	int		x;
	char	**arr;

	arr = malloc(sizeof(char *) * (get_words(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	x = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		arr[x] = copy_next_word(s, c, &i);
		if (!arr[x])
		{
			free_split(arr, x);
			return (NULL);
		}
		x++;
	}
	arr[x] = NULL;
	return (arr);
}